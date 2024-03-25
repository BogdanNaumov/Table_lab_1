#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include "MyStack.h"
using namespace std;

HANDLE hConsole;

int main()
{
    setlocale(LC_ALL, "Russian");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    int tmp_size = 0, tmp_num=0,tmp_element=0;
    cout << "Какой длинны хотите создать стек: ";
    cin >> tmp_size;
    if (tmp_size<1 || tmp_size>100) { throw invalid_argument("Некорректное значение размера!"); }
    system("cls");
    cout << "Поочерёдно введите элементы стека: ";
    TStack<int> tmp(tmp_size);
    cin >> tmp;
    system("cls");

    while (tmp_num!=6) 
    {
        cout << "    Работа со стеком" << endl;
        SetConsoleTextAttribute(hConsole, 3);
        cout << "1 - Добавить Элемент" << endl;
        cout << "2 - Извлечь Элемент" << endl;
        cout << "3 - Элемент на вершине" << endl;
        cout << "4 - Размер стека" << endl;
        cout << "5 - Вывод стека" << endl;
        cout << "6 - Закончить" << endl;
        cout << endl << "Ввод: ";
        cin >> tmp_num;
        switch (tmp_num)
        {
        case 1:
            system("cls");
            cout << "Введите элемент: ";
            cin >> tmp_element;
            tmp.Push(tmp_element);
            system("cls");
            break;
        case 2:
            tmp.Pop();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "Элемент на вершине стека - " << tmp.TopView();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "Ваш стек состоит из " << tmp.GetSize() << " Элементов"<<endl;
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << tmp<<endl;
            system("pause");
            system("cls");
            break;
        default:
            break;
        }

    }

}
