#pragma once
#include "Base_Table.h" 
#include "TList.h" 
#include <iostream> 
#include <utility> 

template <typename TKey, typename TValue>
class Unordered_Table : public Base_Table<TKey, TValue> {
private:
    struct Node {
        TKey key;
        TValue value;
        Node* next;

        Node(const TKey& k, const TValue& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;
    int count; 

    Node* FindNode(TKey key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key)
                return current;
            current = current->next;
        }
        return nullptr;
    }

public:
    Unordered_Table() : head(nullptr), count(0) {}

    bool IsFull() const override {
        return false; 
    }

    TValue* Find(TKey key) override {
        Node* node = FindNode(key);
        if (node != nullptr) {
            return &(node->value);
        }
        else {
            return nullptr;
        }
    }

    void Insert(TKey key, TValue value) override {
        Node* newNode = new Node(key, value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }

    void Delete(TKey key) override {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                count--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    int Reset() override {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        count = 0;
        return 0; 
    }

    int IsTabEnded() const override {
        return (head == nullptr);
    }

    int GoNext() override {
        return 0; 
    }

    TKey GetKey() const override {
        if (head == nullptr)
            throw out_of_range("Table is empty");
        return head->key;
    }

    TValue GetValuePtr() const override {
        if (head == nullptr)
            throw out_of_range("Table is empty");
        return head->value;
    }

    ostream& Print(ostream& os) const override {
        Node* current = head;
        os << "Неупорядоченная таблица на листе:" << endl;
        while (current != nullptr) {
            os << "Ключ: " << current->key << ", Значение: " << current->value << endl;
            current = current->next;
        }
        return os;
    }

};


// Добавляем оператор << для удобства вывода
template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const Unordered_Table<TKey, TValue>& table) {
    return table.Print(os);
}
