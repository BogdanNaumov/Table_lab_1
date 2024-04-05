#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");
    TableManager<int, TPolinom> manager;

   
    UnorderedTable_mas<int, TPolinom> table1;
    SortArrayTable<int, TPolinom> table2;
    Unordered_Table<int, TPolinom>table3;
    AVL_Tree<int, TPolinom> table4;
    ProbingHashTable<int, TPolinom>table5;
    ChainingHashTable<int, TPolinom>table6;
    manager.AddTable(&table1);
    manager.AddTable(&table2);
    manager.AddTable(&table3);
    manager.AddTable(&table4);
    manager.AddTable(&table5);
    manager.AddTable(&table6);
    int choice;
    typedef int TKey; 
    typedef TPolinom TValue;

    do {
        cout << "Выберите операцию:" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Сбросить все таблицы" << endl;
        cout << "4. Найти элемент" << endl;
        cout << "5. Проверить, заполнены ли таблицы полностью" << endl;
        cout << "6. Вывести все таблицы" << endl;
        cout << "7. Вывести конкретную таблицу" << endl;
        cout << "0. Выйти из программы" << endl;
        cin >> choice;
        TKey key;
        TValue value;
        switch (choice) {
        case 1:
            cout << "Введите ключ и значение для добавления:" << endl;
            cin >> key >> value;
            manager.InsertElement(key, value);
            break;
        case 2:
            cout << "Введите ключ для удаления элемента:" << endl;
            cin >> key;
            manager.DeleteElement(key);
            break;
        case 3:
            manager.ResetAllTables();
            break;
        case 4:
            cout << "Введите ключ для поиска:" << endl;
            cin >> key;
            manager.FindElement(key);
            break;
        case 5:
            manager.IsFullElement();
            break;
        case 6:
            manager.PrintAllTables();
            break;
        case 7:
            int tableIndex;
            cout << "Введите индекс таблицы для вывода:" << endl;
            cin >> tableIndex;
            manager.PrintTable(tableIndex);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}