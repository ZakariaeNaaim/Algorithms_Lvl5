#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T> class clsMyQueue {

protected:
	clsDblLinkedList <T> _MyList;

public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	clsDblLinkedList::Node* GetItem(short index) {
		return _MyList.GetItem(index);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	bool UpdateItem(short index, T value) {
		return _MyList.UpdateItem(index, value);
	}

	bool InsertAfter(short index, T value) {
		return _MyList.InsertAfter(index, value);
	}

	bool InsertAtFront(T value) {
		return _MyList.InsertAtBeginning(value);
	}

	bool InsertAtBack(T value) {
		return _MyList.InsertAtEnd(value);
	}

	bool Clear() {
		return _MyList.Clear();
	}

	
};