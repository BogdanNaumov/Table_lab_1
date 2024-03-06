#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;  // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList() : TList<T>()
{
	this->pHead = nullptr;
}

template<class T>
THeadList<T>::~THeadList()
{

}

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	if (length == 0) {
		pFirst = new TNode<T>(item, this->pHead, this->pLast);
		pCurrent = pFirst;
		pLast = pFirst;
		pStop = pLast->pNext;
	}
	else {
		TNode<T>* tmp = this->pCurrent;
		this->pCurrent = this->pFirst;
		this->InsertCurrent(item);
		this->pCurrent = tmp;
	}
	length++;
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	if (this->pCurrent == this->pFirst) {
		TNode<T>* tmp = this->pFirst->pNext;
		this->DeleteCurrent();
		this->pCurrent = tmp;

	}
	else {
		TNode<T>* tmp = this->pCurrent;
		this->pCurrent = this->pFirst;
		this->DeleteCurrent();
		this->pCurrent = tmp;
	}
	
}