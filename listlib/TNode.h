#pragma once

template<class T>
struct TNode
{
	T value;
	TNode* pNext;
	TNode* pPrev;
	TNode(T _value, TNode<T>* _pPrev = nullptr, TNode<T>* _pNext = nullptr) {
		this->value = _value;
		this->pPrev = _pPrev;
		this->pNext = _pNext;
	}
};
