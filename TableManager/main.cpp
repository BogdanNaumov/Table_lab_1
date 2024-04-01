#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");
    TableManager<int, TPolinom> manager;

   
    UnorderedTable_mas<int, TPolinom> table1;
    SortArrayTable<int, TPolinom> table2;
    AVL_Tree<int, TPolinom> table3;
    manager.AddTable(&table1);
    manager.AddTable(&table2);
    manager.AddTable(&table3);

    
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
    
    for (int i = 0; i < 3; i++) 
    {
        manager.InsertElement(i, 1, p1);
        manager.InsertElement(i, 2, p2);
        manager.InsertElement(i, 3, p3);
        manager.InsertElement(i, 4, p4);
    }
    

    
    manager.PrintTable(2);
    manager.DeleteElement(2, 3);

    manager.PrintTable(2);
    manager.IsFullElement(2);


    return 0;
}