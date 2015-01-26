#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <fcntl.h>
#include "testcase3.h"
#include <error.h>

using namespace std;

sem_t semA;
sem_t semB;
sem_t semC;

void* fun_a(void* args)
{
	for(int i = 0; i<=9; i++)
	{
		sem_wait(&semA);//wait for semA
		cout << pthread_self() << ": A" << endl;
		sem_post(&semB);//release semB
	}
}

void* fun_b(void* args)
{
	for(int i = 0; i<=9; i++)
	{
		sem_wait(&semB);//wait for semB
		cout << pthread_self() << ": B" << endl;
		sem_post(&semC);//release semC
	}
}

void* fun_c(void* args)
{
	for(int i = 0; i<=9; i++)
	{
		sem_wait(&semC);//wait for semC
		cout << pthread_self() << ": C" << endl;
		sem_post(&semA);//release semA
	}
}

void TestCase3()
{
#if 1
	int erra = sem_init(&semA,0,1);
	int errb = sem_init(&semB,0,0);
	int errc = sem_init(&semC,0,0);
    if((erra != 0) || (errb != 0) || (errc != 0))
    {
        cout << "err when init semaphore!" << endl;
    }
#endif

	pthread_t pid1,pid2,pid3;

	pthread_attr_t attr;	//Ҫ?봴??ʱ????????????????
	pthread_attr_init(&attr);	//?ٳ?ʼ??
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//???����?ʼ??????????????????????Ҫָ???߳????Բ??????????????????????߳??ǿ???join��?ӵģ?join???ܱ?ʾ?????????Ե??߳̽???????ȥ??ĳ?£?ʵ?????????????߳?ͬ?????ܣ?????????????????ͨ??ͼʾ???ܽ??ͣ????????????ϰ?

	pthread_create(&pid1, &attr, fun_a,NULL);
	pthread_create(&pid2, &attr, fun_b,NULL);
	pthread_create(&pid3, &attr, fun_c,NULL);

	void *status;
	int ret = pthread_join(pid1, &status);
	if (ret != 0)
    {
        cout << "pthread_join error: error_code=" << ret << endl;
    }
    else
    {
        cout << "pthread_join get status: " << (long)status << endl;
    }

	ret = pthread_join(pid2, &status);
	if (ret != 0)
    {
        cout << "pthread_join error: error_code=" << ret << endl;
    }
    else
    {
        cout << "pthread_join get status: " << (long)status << endl;
    }
	ret = pthread_join(pid3, &status);
	if (ret != 0)
    {
        cout << "pthread_join error: error_code=" << ret << endl;
    }
	pthread_attr_destroy(&attr);//????ʹ?????˾Ϳ????????ˣ?????????Ŷ????ֹ?ڴ?й¶?

	sem_destroy(&semA);
	sem_destroy(&semB);
	sem_destroy(&semC);
}





