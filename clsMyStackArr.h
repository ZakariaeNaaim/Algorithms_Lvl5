#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

template <class T> class clsMyStackArr : public clsMyQueueArr<T> {


public:

	clsMyStackArr(){}

	void push(T Item)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(Item);
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::front();
	}

	T Top()
	{
		return clsMyQueueArr<T>::back();
	}
};