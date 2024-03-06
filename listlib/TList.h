#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // первое звено
	TNode<T>* pCurrent; // текущее звено
	TNode<T>* pPrevious; // звено перед текущим
	TNode<T>* pLast; // последнее звено
	TNode<T>* pStop; // значение указателя, означающего конец списка
	int length; // количество звеньев в списке

public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty(); // список пуст ?
	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим 
	void InsertLast(T item);  // вставить последним 

	// удаление звеньев
	void DeleteFirst(); // удалить первое звено 
	void DeleteCurrent(); // удалить текущее звено

	void GoNext(); // сдвиг вправо текущего звена
	// (=1 после применения GoNext для последнего звена списка)
	void GoPrev();

	void Reset(); // установить на начало списка
	bool IsEnd();  // список завершен ?

	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }


};
template <class T>
TList<T>::TList()
{
	length = 0;
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = nullptr;

	pStop = pLast;
}

template <class T>
TList<T>::~TList()
{
	length = 0;
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = nullptr;
}

template <class T>
bool TList<T>::IsEmpty()
{
	if (length == 0) return true;
	else return false;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	if (length == 0) {
		pFirst = new TNode<T>(item);
		pFirst->pNext = pLast;
		pCurrent = pFirst;
		pLast = pFirst;
		pStop = pLast->pNext;
	}
	else {
		TNode<T>* tmp = new TNode<T>(item, nullptr, pFirst);
		pFirst->pPrev = tmp;
		pFirst = tmp;
	}
	length++;
}

template <class T>
void TList<T>::InsertLast(T item)
{
	if (length == 0) {
		pFirst = new TNode<T>(item);
		pFirst->pNext = pLast;
		pCurrent = pFirst;
		pLast = pFirst;
		pStop = pLast->pNext;
	}
	else {
		TNode<T>* tmp = new TNode<T>(item, pLast, nullptr);
		pLast->pNext = tmp;
		pLast = tmp;
	}
	length++;
}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == pFirst) {
		TNode<T>* tmp = new TNode<T>(item, nullptr, pFirst);
		pFirst->pPrev = tmp;
		pFirst = tmp;
	}
	else {
		TNode<T>* tmp = pCurrent->pPrev;
		TNode<T>* n = new TNode<T>(item, tmp, pCurrent);

		tmp->pNext = n;
		pCurrent->pPrev = n;
	}
	length++;
}

template <class T>
void TList<T>::DeleteFirst()
{
	if (pCurrent == pFirst) pCurrent = pFirst->pNext;
	TNode<T>* tmp = pFirst;
	if (pFirst != nullptr) {
		pFirst = pFirst->pNext;
	} 

	if (pFirst != nullptr) {
		pFirst->pPrev = nullptr;
	} 
	else pLast = pFirst;

	delete tmp;
	length--;
}

template <class T>
void TList<T>::DeleteCurrent()
{
	if (pCurrent == pFirst)
		DeleteFirst();
	else {
		if (pCurrent == pLast) {
			TNode<T>* tmp = pCurrent->pPrev;
			tmp->pNext = nullptr;
			
			TNode<T>* tmp2 = pCurrent;
			pCurrent = tmp;
			pLast = tmp;

			delete tmp2;

		}
		else {
			TNode<T>* tmp = pCurrent->pPrev;
			tmp->pNext = pCurrent->pNext;

			TNode<T>* tmp2 = pCurrent->pNext;
			tmp2->pPrev = pCurrent->pPrev;

			tmp = pCurrent;
			pCurrent = tmp2;
			delete tmp;
		}
		length--;
	}
	
	
}

template <class T>
T TList<T>::GetCurrentItem()
{
	/*if (pCurrent == pStop)
		throw " ";*/
	return pCurrent->value;
}

template <class T>
void TList<T>::Reset()
{
	pCurrent = pFirst;
}

template <class T>
void TList<T>::GoNext()
{
	if (pCurrent == pLast) pCurrent = pFirst;
	else pCurrent = pCurrent->pNext;
}

template <class T>
void TList<T>::GoPrev()
{
	if (pCurrent == pFirst) pCurrent = pLast;
	else pCurrent = pCurrent->pPrev;
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurrent == pStop;
}





