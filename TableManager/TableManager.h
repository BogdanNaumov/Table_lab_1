#include <iostream>
#include <vector>

#include "..\\Table_arr\Table_arr.h"
#include "..\\Base_Table\Base_Table.h"
#include "..\\polinomlib\TMonom.h"
#include "..\\polinomlib\TPolinom.h"

// Менеджер таблиц
template <typename TKey, typename TValue>
class TableManager {
private:
    std::vector<Base_Table<TKey, TValue>*> tables;

public:
    // Добавить таблицу в менеджер
    void AddTable(Base_Table<TKey, TValue>* table) {
        tables.push_back(table);
    }

    // Вставить элемент в указанную таблицу
    void InsertElement(int tableIndex, TKey key, const TValue& value) {
        if (tableIndex >= 0 && tableIndex < tables.size()) {
            tables[tableIndex]->Insert(key, value);
        }
        else {
            std::cout << "Error: Table index out of range" << std::endl;
        }
    }

    // Вывести содержимое указанной таблицы
    void PrintTable(int tableIndex) {
        if (tableIndex >= 0 && tableIndex < tables.size()) {
            std::cout << "Table content:" << std::endl;
            std::cout << *tables[tableIndex] << std::endl;
        }
        else {
            std::cout << "Error: Table index out of range" << std::endl;
        }
    }

    // Другие методы, такие как удаление элемента из таблицы и т. д.
};

