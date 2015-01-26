#ifndef TESTCASE1_H
#define TESTCASE1_H

#include <pthread.h>

using namespace std;
//namespace TC1{
#if 1
	void* add_val(void* args);
	void TestCase1(int &val);
#endif
#if 0
void* add_val(void* args)
{
	int i;
	int *valPtr = &i;
	for(int i = 1; i<=50; i++)
	{
		*valPtr++;
	}
}

void TestCase1(int &val)
{
	pthread_t pid1, pid2;
	void * valPtr = &val;
	int test;
	pthread_create(&pid1, NULL, add_val,NULL);
	//pthread_create(&pid2, NULL, add_val, valPtr);
	pthread_exit(NULL);
}
#endif

//}

//using namespace TC1;

#endif
