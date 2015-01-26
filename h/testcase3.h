#ifndef TESTCASE3_H
#define TESTCASE3_H

#include <pthread.h>
#include <semaphore.h>

using namespace std;

void* fun_a(void* args);
void* fun_b(void* args);
void* func_c(void* args);
	
void TestCase3(void);

#endif
