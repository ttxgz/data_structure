#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include "testcase2.h"

using namespace std;
//using namespace TC1;

typedef struct test{
	pthread_t pid;
	int *valPtr;
} Test;

pthread_mutex_t val_mutex;

void* add_val_mutex(void* args)
{
	pthread_t pidLocal = ((Test *)args)->pid;
	int *valPtr = ((Test *)args)->valPtr;
	cout << "initial: *args = " << *valPtr << endl;
	
	for(int i = 1; i<=50000; i++)
	{
		pthread_mutex_lock (&val_mutex);//修改sum就先加锁，锁被占用就阻塞，直到拿到锁再修改sum；
		(*valPtr)++;
		pthread_mutex_unlock (&val_mutex);//完事后解锁，释放给其他线程使用;  
	}
	cout << *valPtr << " ";
}

void TestCase2(int &val)
{
	pthread_t pid1, pid2;
	Test test1,test2;

	test1.pid = pid1;
	test1.valPtr = &val;

	test2.pid = pid2;
	test2.valPtr = &val;

	pthread_mutex_init (&val_mutex, NULL);//这句是对锁进行初始化，必须的；
	
	pthread_attr_t attr;	//要想创建时加入参数，先声明 
	pthread_attr_init(&attr);	//再初始化
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//声明、初始化后第三步就是设置你想要指定线程属性参数，这个参数表明这个线程是可以join连接的，join功能表示主程序可以等线程结束后再去做某事，实现了主程序和线程同步功能，这个深层理解必须通过图示才能解释；参阅其他资料吧
	pthread_create(&pid1, &attr, add_val_mutex,(void *)&test1);
	pthread_create(&pid2, &attr, add_val_mutex, (void *)&test2);
	
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
	pthread_attr_destroy(&attr);//参数使用完了就可以销毁了，必须销毁哦，防止内存泄露；
	pthread_mutex_destroy(&val_mutex);
}





