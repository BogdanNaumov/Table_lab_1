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
        // Простейшая хеш-функция, можно заменить на более сложную
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
        // Хеш-таблица с пробированием не бывает полной
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

            // Если вернулись в исходную позицию, значит, прошли по всей таблице
            if (index == startIndex) {
                return nullptr;
            }
        }

        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        int index = Hash(key);
        int startIndex = index;

        // Ищем первый свободный или занятый элемент
        while (table[index] != nullptr && table[index]->occupied && table[index]->key != key) {
            index = (index + 1) % capacity;

            // Если вернулись в исходную позицию, значит, прошли по всей таблице
            if (index == startIndex) {
                throw runtime_error("Hash table is full.");
            }
        }

        // Если нашли занятый элемент с нужным ключом, просто обновляем значение
        if (table[index] != nullptr && table[index]->occupied && table[index]->key == key) {
            table[index]->value = value;
        }
        else {
            // Иначе создаем новый узел и записываем его в таблицу
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

            // Если вернулись в исходную позицию, значит, прошли по всей таблице
            if (index == startIndex) {
                return; // Элемент не найден
            }
        }
    }

    int IsTabEnded(void) const override {
        // В хеш-таблице нет конца, так как мы можем продолжать добавлять элементы
        return false;
    }

    int GoNext(void) override {
        return 1;
    }

    int Reset(void) override {
        // Просто очищаем таблицу
        for (int i = 0; i < capacity; ++i) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }
        return 0;
    }

    TKey GetKey(void) const override {
        // Метод не реализован, так как он не применим к данной структуре данных
        return TKey();
    }

    TValue GetValuePtr(void) const override {
        // Метод не реализован, так как он не применим к данной структуре данных
        return TValue();
    }

    ostream& Print(ostream& os) const override {
        os << "Probing Hash Table:" << endl;
        for (int i = 0; i < capacity; ++i) {
            if (table[i] != nullptr && table[i]->occupied) {
                os << " Index: " << i << " Key: " << table[i]->key << " Value: " << table[i]->value << endl;
            }
        }
        return os;
    }

    ~ProbingHashTable() {
        // Освобождаем память, выделенную для узлов
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
