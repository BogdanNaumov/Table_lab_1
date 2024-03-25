#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>

using namespace std;

template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;
public:
	TStack(int n);
	TStack(TStack<T>& stack);
	~TStack();

	void Push(T a);
	T Pop();
	T TopView();

	int GetSize();
	int GetTop();

	bool IsFull();
	bool IsEmpty();

	TStack& operator=(const TStack<T>& stack);

	friend ostream& operator<<(ostream& os, const TStack<T>& stack)
	{
		for (int i = 0; i < stack.top; i++) {
			os << stack.mas[i] << ' ';
		}
		return os;
	}

	friend istream& operator>>(istream& is,  TStack<T>& stack)
	{
		for (int i = 0; i < stack.size; i++) {
			is >> stack.mas[i];
			stack.top++;
		}
		return is;
	}

};

template <class T>
TStack<T>::TStack(int n) {
	if (n < 1)
		throw "Некорректный размер";
	size = n;
	top = 0;
	mas = new T[size];
}

template <class T>
TStack<T>::TStack(TStack<T>& stack) {
	size = stack.size;
	top = stack.top;
	mas = new T[size];
	copy(stack.mas, stack.mas + stack.size, mas);
}

template <class T>
TStack<T>::~TStack() {
	delete[] mas;
}

template <class T>
void TStack<T>::Push(T a) {
	if (IsFull()) {
		throw "Стек заполнен";
	}
	mas[top] = a;
	top++;
}

template<class T>
T TStack<T>::Pop()
{
	if (IsEmpty())
		throw "Стек пуст";
	top--;
	return mas[top];
}

template <class T>
T TStack<T>::TopView() {
	if (IsEmpty()) {
		throw "Стек пуст";
	}
	return mas[top-1];
}


template <class T>
int TStack<T>::GetSize() {
	return size;
}

template <class T>
int TStack<T>::GetTop() {
	return top - 1;
}

template <class T>
bool TStack<T>::IsFull() {
	return top == size;
}

template <class T>
bool TStack<T>::IsEmpty() {
	return top == 0;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& stack) {
	if (this == &stack) {
		return *this;
	}
	delete[] mas;
	size = stack.size;
	top = stack.top;
	mas = new T[size];
	copy(stack.mas, stack.mas + stack.size, mas);
	return *this;
}

#endif