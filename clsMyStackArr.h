#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

template <class T> class clsMyStack : public clsMyQueueArr<T> {


public:

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