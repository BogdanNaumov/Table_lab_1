#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    // Создаем менеджер таблиц
    TableManager<int, TPolinom> manager;

    // Создаем и добавляем таблицу в менеджер
    SortArrayTable<int, TPolinom> table1;
    manager.AddTable(&table1);

    // Создаем полиномы
    TPolinom p1, p2;
    // Добавляем полиномы в таблицу через менеджер
    manager.InsertElement(0, 1, p1);
    manager.InsertElement(0, 2, p2);

    // Выводим содержимое таблицы через менеджер
    manager.PrintTable(0);

    return 0;
}