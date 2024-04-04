#include <iostream>
#include <vector>
#include "..\\Three_avl\Three_avl.h"
#include "..\\hesh_1\hesh_1.h"
#include "..\\hesh_2\hesh_2.h"
#include "..\\UnorderedTable_arr\UnorderedTable_arr.h"
#include "..\\Table_arr\Table_arr.h"
#include "..\\Base_Table\Base_Table.h"
#include "..\\polinomlib\TMonom.h"
#include "..\\polinomlib\TPolinom.h"
#include "..\\UnorderedTable_list\UnorderedTable_list.h"

using namespace std;

template <typename TKey, typename TValue>
class TableManager {
private:
    vector<Base_Table<TKey, TValue>*> tables;

public:
    void AddTable(Base_Table<TKey, TValue>* table) {
        tables.push_back(table);
    }

    void InsertElement(TKey key, TValue value) {
        for (auto table : tables) {
            table->Insert(key, value);
        }
    }

    void DeleteElement(TKey key) {
        for (auto table : tables) {
            table->Delete(key);
        }
    }

    void ResetAllTables() {
        for (auto table : tables) {
            table->Reset();
        }
    }

    void FindElement(TKey key) {
        for (auto table : tables) {
            TValue* value = table->Find(key);
            if (value != nullptr) {
                cout << "Элемент найден в таблице " << table << ": " << *value << endl;
            }
            else {
                cout << "Элемент с ключом " << key << " не найден в таблице " << table << endl;
            }
        }
    }

    void IsFullElement() {
        for (auto table : tables) {
            if (table->IsFull()) {
                cout << "Таблица " << table << " заполнена." << endl;
                return;
            }
        }
        cout << "Все таблицы еще имеют свободное место." << endl;
    }
    void PrintAllTables() {
        for (size_t i = 0; i < tables.size(); ++i) {
            cout << "Таблица " << i << ":" << endl;
            cout << *tables[i] << endl;
        }
    }
    void PrintTable(int tableIndex) {
        cout << "Подключение к таблице:" << endl;
        if (tableIndex >= 0 && tableIndex < tables.size()) {
            cout << *tables[tableIndex] << endl;
        }
        else {
            cout << "Error: Table index out of range" << endl;
        }
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const Base_Table<TKey, TValue>& table) {
    return table.Print(os);
}


