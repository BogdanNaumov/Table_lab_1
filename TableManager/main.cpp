#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");
    TableManager<int, TPolinom> manager;

   
    UnorderedTable_mas<int, TPolinom> table1;
    SortArrayTable<int, TPolinom> table2;
    AVL_Tree<int, TPolinom> table3;
    ProbingHashTable<int, TPolinom>table4;
    ChainingHashTable<int, TPolinom>table5;
    Unordered_Table<int, TPolinom>table6;
    manager.AddTable(&table1);
    manager.AddTable(&table2);
    manager.AddTable(&table3);
    manager.AddTable(&table4);
    manager.AddTable(&table5);
    manager.AddTable(&table6);

    
    TPolinom p1, p2,p3,p4;
    TMonom a(3.22, 2, 2, 1);
    TMonom b(2.5, 1, 3, 3);
    TMonom c(3.4, 2, 4, 4);
    TMonom d(4.22, 2, 2, 3);
    TMonom e(2.5, 3, 7, 7);
    p2.AddMonom(d);
    p2.AddMonom(e);
    p1.AddMonom(a);
    p1.AddMonom(b);
    p1.AddMonom(c);
    p3.AddMonom(a);
    p3.AddMonom(b);
    p4.AddMonom(a);
    p4.AddMonom(e);

    int choice;
    typedef int TKey; // Замените тип данных int на соответствующий тип ключа
    typedef TPolinom TValue; // Замените TPolinom на соответствующий тип значения
    TKey key;
    TValue value;

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