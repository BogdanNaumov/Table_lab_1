#pragma once
#include "..\\Base_Table\Base_Table.h"
#include <iostream>

using namespace std;

template <typename TKey, typename TValue>
class ProbingHashTable : public Base_Table<TKey, TValue> {
private:
    struct Node {
        TKey key;
        TValue value;
        bool occupied;

        Node() : occupied(false) {}
    };

    Node** table;
    int capacity;

    int Hash(const TKey& key) const {
        return key % capacity;
    }

public:
    ProbingHashTable() : capacity(10) {
        table = new Node * [capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }
    }

    ProbingHashTable(int size) : capacity(size) {
        table = new Node * [capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }
    }

    bool IsFull() const override {
        return false;
    }

    TValue* Find(TKey key) override {
        int index = Hash(key);
        int startIndex = index;

        while (table[index] != nullptr && table[index]->occupied) {
            if (table[index]->key == key) {
                return &(table[index]->value);
            }

            index = (index + 1) % capacity;

            if (index == startIndex) {
                return nullptr;
            }
        }

        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        int index = Hash(key);
        int startIndex = index;

        while (table[index] != nullptr && table[index]->occupied && table[index]->key != key) {
            index = (index + 1) % capacity;

            if (index == startIndex) {
                throw runtime_error("Hash table is full.");
            }
        }

        if (table[index] != nullptr && table[index]->occupied && table[index]->key == key) {
            table[index]->value = value;
        }
        else {

            Node* newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->occupied = true;
            table[index] = newNode;
        }
    }

    void Delete(TKey key) override {
        int index = Hash(key);
        int startIndex = index;

        while (table[index] != nullptr && table[index]->occupied) {
            if (table[index]->key == key) {
                delete table[index];
                table[index] = nullptr;
                return;
            }

            index = (index + 1) % capacity;
            if (index == startIndex) {
                return; 
            }
        }
    }

    int IsTabEnded(void) const override {
        return false;
    }

    int GoNext(void) override {
        return 1;
    }

    int Reset(void) override {
        for (int i = 0; i < capacity; ++i) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }
        return 0;
    }

    TKey GetKey(void) const override {
        return TKey();
    }

    TValue GetValuePtr(void) const override {
        return TValue();
    }

    ostream& Print(ostream& os) const override {
        os << "Probing Hash Table:" << endl;
        for (int i = 0; i < capacity; ++i) {
            if (table[i] != nullptr && table[i]->occupied) {
                os << " Индекс: " << i << " Ключ: " << table[i]->key << " Значение: " << table[i]->value << endl;
            }
        }
        return os;
    }

    ~ProbingHashTable() {
        for (int i = 0; i < capacity; ++i) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        delete[] table;
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const ProbingHashTable<TKey, TValue>& table) {
    return table.Print(os);
}
