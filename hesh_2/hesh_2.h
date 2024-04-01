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
        // Простейшая хеш-функция, можно заменить на более сложную
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
        // Хеш-таблица на основе цепочек не бывает полной
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

        // Если список для данного индекса пуст, просто вставляем новый узел
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            // В противном случае добавляем новый узел в начало списка
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
        // В хеш-таблице нет конца, так как мы можем продолжать добавлять элементы
        return false;
    }
    int GoNext(void) override
    {
        return 1;
    }

    int Reset(void) override {
        // Очищаем таблицу и освобождаем память
        for (int i = 0; i < capacity; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
        }
        delete[] table;
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
        os << "Chaining Hash Table:" << endl;
        for (int i = 0; i < capacity; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                os << " Index: " << i << " Key: " << current->key << " Value: " << current->value << endl;
                current = current->next;
            }
        }
        return os;
    }

    ~ChainingHashTable() {
        // Освобождаем память, выделенную под связанные списки
        Reset();
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const ChainingHashTable<TKey, TValue>& table) {
    return table.Print(os);
}
