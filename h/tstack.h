#ifndef TSTACK_H
#define TSTACK_H


using namespace std;

template <class type, int maxSize> class tstack{
	type* stack;
	int top;

public:
	tstack();
	void push(const type & item);
	type pop();
	~tstack();
};

//critical for template when we want to define function/class template in a seperate cpp file. 
#include "../src/tstack.cpp"


#endif
