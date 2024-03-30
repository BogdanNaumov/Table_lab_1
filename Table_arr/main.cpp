#include "Table_arr.h"
#include "TList.h"
#include "TPolinom.h"
#include <iostream>

int main() {
    // Создаем полиномы
    TPolinom p1;
    TMonom a(3.22, 2, 2, 1);
    TMonom b(2.5, 1, 3, 3);
    TMonom c(3.4, 2, 4, 4);
    p1.AddMonom(a);
    p1.AddMonom(b);
    p1.MultMonom(c);

    TPolinom p2;
    TMonom d(4.22, 2, 2, 3);
    TMonom e(2.5, 3, 7, 7);
    p2.AddMonom(d);
    p2.AddMonom(e);

    // Создаем таблицу и добавляем полиномы
    SortArrayTable<int, TPolinom> table;
    table.Insert(1, p1);
    table.Insert(2, p2);

    // Выводим содержимое таблицы
    std::cout << "Table content:" << std::endl;
    std::cout << table << std::endl;

    return 0;
}
