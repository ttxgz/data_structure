#include <iostream>
#include <stdexcept>

using namespace std;

// DO NOT need this include because this cpp will not be compiled until instantiated in main then the header file is read. 
//#include "stack.h"

template <class T, int MaxSize> tstack<T, MaxSize>::tstack():top(0)
{
	stack = new T[MaxSize];
}

template <class T, int MaxSize>
void tstack<T, MaxSize>::push(const T & item)
{
	if(top <= (MaxSize - 1))
	{
		stack[top++] = item;
	}
	else
	{
		throw runtime_error("the stach has reached the maximum size!");
	}
}

template <class T, int MaxSize>
T tstack<T, MaxSize>::pop()
{
	T item;
	if(top >= 0)
	{
		item = stack[--top];
	}
	else
	{
		throw runtime_error("the stach is empty!");
	}
	return item;
}

template <class T, int MaxSize>
tstack<T, MaxSize>::~tstack()
{
	delete[] stack;
}


