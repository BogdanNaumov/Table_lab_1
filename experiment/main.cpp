#include <iostream>
#include <chrono>
#include <random>
#include "experiment.h" 


#define NUM_VALUES 1

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Experiment<int, TPolinom> experiment;
    typedef int TKey;
    typedef TPolinom TValue;
    TKey key;
    TValue value;


    UnorderedTable_mas<int, TPolinom> table1;
    Unordered_Table<int, TPolinom>table2;
    SortArrayTable<int, TPolinom> table3;
    AVL_Tree<int, TPolinom> table4;
    ProbingHashTable<int, TPolinom>table5;
    ChainingHashTable<int, TPolinom>table6;

    experiment.AddTable(&table1);
    experiment.AddTable(&table2);
    experiment.AddTable(&table3);
    experiment.AddTable(&table4);
    experiment.AddTable(&table5);
    experiment.AddTable(&table6);
    


    for (int i = 1; i < 30000; i++) 
    {
        TPolinom tmp;
        TMonom tmp_(30, 1, 1, 1);
        tmp.AddMonom(tmp_);
        experiment.InsertElement_1(i,tmp);
    }
    //experiment.InsertRandomValues(3, 5, 10);
    cout <<"____________________________________________"<<endl;
    experiment.FindElement(15000);
    cout << "____________________________________________" << endl;
    experiment.DeleteElement(15000);
    cout << "____________________________________________" << endl;
    TPolinom tmp;
    TMonom tmp_(30, 1, 1, 1);
    tmp.AddMonom(tmp_);
    experiment.InsertElement(15000, tmp);
    cout << "____________________________________________" << endl;
    return 0;
}
