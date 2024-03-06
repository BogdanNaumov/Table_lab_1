#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Полином p1 с одним мономом a(3.22, 1, 2, 1):" << endl;
	TPolinom p1;
	TMonom a(3.22, 2, 2, 1);
	TMonom b(2.5, 1, 3, 3);
	TMonom c(3.4, 2, 4, 4);
	TPolinom p2;
	TMonom d(4.22, 2, 2, 3);
	TMonom e(2.5, 3, 7, 7);
	p2.AddMonom(d);
	p2.AddMonom(e);

	p1.AddMonom(a);
	cout << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;

	p1.AddMonom(b);
	cout << "p1.AddMonom(b(2.5, 1, 3, 3)):" << endl << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;

	p1.MultMonom(c);
	cout << "p1.MultMonom(c(3.4, 2, 4, 4)):" << endl << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;

	
	string str;

	cout << "TPolinom p2(str):" << endl << p2.ToString() << endl;
	cout << "_________________________________________________" << endl;

	cout<< p1.ToString() << endl;
	cout << p2.ToString() << endl;
	p1.AddPolinom(p2);
	cout << "p1.AddPolinom(p2):" << endl << p1.ToString() << endl;



	
	

}