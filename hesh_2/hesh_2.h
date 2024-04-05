#include "..\\Base_Table\Base_Table.h"
#include <iostream>

using namespace std;

template <typename TKey, typename TValue>
class ChainingHashTable : public Base_Table<TKey, TValue> {
private:
    struct Node {
        TKey key;
        TValue value;
        Node* next;

        Node(const TKey& k, const TValue& v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;
    int capacity;

    int Hash(const TKey& key) const {
        return key % capacity;
    }

public:
    ChainingHashTable() : capacity(100) {
        table = new Node * [capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }
    }

    ChainingHashTable(int size) : capacity(size) {
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
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return &(current->value);
            }
            current = current->next;
        }

        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        int index = Hash(key);
        Node* newNode = new Node(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    void Delete(TKey key) override {
        int index = Hash(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    int IsTabEnded(void) const override {
        return false;
    }
    int GoNext(void) override
    {
        return 1;
    }

    int Reset(void) override {
        for (int i = 0; i < capacity; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
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
        os << "Chaining Hash Table:" << endl;
        for (int i = 0; i < capacity; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                os << " Индекс: " << i << " Ключ: " << current->key << " Значение: " << current->value << endl;
                current = current->next;
            }
        }
        return os;
    }

    ~ChainingHashTable() {
        Reset();
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const ChainingHashTable<TKey, TValue>& table) {
    return table.Print(os);
}
