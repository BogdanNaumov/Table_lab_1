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
class Experiment {
private:
    vector<Base_Table<TKey, TValue>*> tables;

public:
    void AddTable(Base_Table<TKey, TValue>* table) {
        tables.push_back(table);
    }

    void InsertElement_1(TKey key, TValue value) {
        for (size_t i = 0; i < tables.size(); i++) {
            tables[i]->Insert(key, value);
        }
    }

    void InsertElement(TKey key, TValue value) {
        for (size_t i = 0; i < tables.size(); i++) {
            auto start = chrono::steady_clock::now();
            tables[i]->Insert(key, value);
            auto end = chrono::steady_clock::now();
            cout << "Элемент вставлен в таблицу " << i << " за время " << chrono::duration<double, std::milli>(end - start).count() << endl;
        }
    }

    void DeleteElement(TKey key) {
        for (size_t i = 0; i < tables.size(); i++) {
            auto start = chrono::steady_clock::now();
            tables[i]->Delete(key);
            auto end = chrono::steady_clock::now();
            cout << "Элемент удалён в таблице " << i << " за время " << chrono::duration<double, std::milli>(end - start).count()<< endl;
        }
    }

    void ResetAllTables() {
        for (auto table : tables) {
            table->Reset();
        }
    }

    void FindElement(TKey key) {
        for (size_t i = 0; i < tables.size(); ++i) {
            auto start = chrono::steady_clock::now();
            TValue* value = tables[i]->Find(key);
            auto end = chrono::steady_clock::now();
            if (value != nullptr) {
                cout << "Элемент найден в таблице " << i <<" за время " << chrono::duration<double, std::milli>(end - start).count()<< endl;
            }
            else {
                cout << "Элемент с ключом " << key << " не найден в таблице " << i << endl;
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
    void InsertRandomValues(int numValues, int lowerBound, int upperBound) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(lowerBound, upperBound);

        for (auto table : tables) {
            for (int i = 0; i < numValues; ++i) {
                TKey key = i;
                TPolinom tmp;
                TMonom tmp_m(dis(gen), dis(gen), dis(gen), dis(gen));
                tmp.AddMonom(tmp_m);
                TValue value = tmp;
                table->Insert(key, value);
            }
        }
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const Base_Table<TKey, TValue>& table) {
    return table.Print(os);
}


