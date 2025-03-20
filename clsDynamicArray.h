#pragma once

#include <iostream>

using namespace std;

template <class T> class clsDynamicArray {
	
private:
	void Swap(T& Val1, T& Val2) {
		T tmp = Val1;
		Val1 = Val2;
		Val2 = tmp;
	}

protected:
	int _Size = 0;
	T* _TempArray;

public : 
	T* OriginalArray;

	clsDynamicArray(int Size) {
		if (Size < 0)
			_Size = 0;

		OriginalArray = new T[Size];
		_Size = Size;
	}

	~clsDynamicArray() {
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || _Size < 0)
			return false;

		OriginalArray[Index] = Value;
		return true;
	}

	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return _Size == 0;
	}

	void PrintList() {
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}

	void Resize(int NewSize) {
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		//limit the original size to the new size if it is less.
		if (NewSize < _Size)
			_Size = NewSize;

		//copy all data from original array until the size
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int Index) {
		if (Index < 0 || Index > _Size)
			return NULL;

		return OriginalArray[Index];
	}

	void Reverse() {
		for (int i = 0; i < _Size/2; i++)
		{
			Swap(OriginalArray[i], OriginalArray[_Size - 1 - i]);
		}
	}

	void Clear() {
		delete[] OriginalArray;
		_Size = 0;
		OriginalArray = new T[0];
		// or Call Resize()
	}

	bool DeleteItemAt(int index) {
		if (index >= _Size || index < 0)
			return false;

		_Size--;

		_TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		//copy all after index
		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void DeleteFirstItem() {
		DeleteItemAt(0);
	}

	void DeleteLastItem() {
		DeleteItemAt(_Size-1);
	}

	int Find(T Value) {
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
				return i;
		}
		return -1;
	}

	void DeleteItem(T Value) {
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value) {
				DeleteItemAt(i);
				i--;
			}
		}
	}

	bool InsertAt(int index, T Value) {
		if (index > _Size || index < 0)
			return false;

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[index] = Value;

		for (int i = index+1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i-1];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T Value) {
		InsertAt(0, Value);
	}

	bool InsertAtEnd(T Value) {
		return InsertAt(_Size, Value);
	}

	bool InsertBefore(int index, T Value) {
		return (index < 1) ? InsertAtBeginning(Value) : InsertAt(index - 1, Value);
	}

	bool InsertAfter(int index, T Value) {
		return (index >= _Size) ? InsertAt(_Size - 1, Value) : InsertAt(index + 1, Value);
	}

};