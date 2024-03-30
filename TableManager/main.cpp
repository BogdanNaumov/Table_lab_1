#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");
    TableManager<int, TPolinom> manager;

   
    SortArrayTable<int, TPolinom> table1;
    manager.AddTable(&table1);

    
    TPolinom p1, p2,p3;
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
    
    manager.InsertElement(0, 1, p1);
    manager.InsertElement(0, 2, p2);
    manager.InsertElement(0, 3, p3);

    
    manager.PrintTable(0);
    manager.DeleteElement(0, 2);

    manager.PrintTable(0);
    manager.IsFullElement(0);

    manager.ResetElement(0);
    manager.PrintTable(0);

    return 0;
}