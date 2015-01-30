#ifndef TESTCASE4_H
#define TESTCASE4_H

#include <pthread.h>
#include <semaphore.h>

using namespace std;

#define BUF_NUMBER 4
#define PRODUCER_NUM 4
#define CONSUMER_NUM 4
#define MAX_PRODUCT_NUM  1

void* producer(void* args);
void* consumer(void* args);

void TestCase4(void);

#endif
