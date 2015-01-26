#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include "testcase1.h"

using namespace std;
//using namespace TC1;

typedef struct test{
	pthread_t pid;
	int *valPtr;
} Test;

void* add_val(void* args)
{
	pthread_t pidLocal = ((Test *)args)->pid;
	int *valPtr = ((Test *)args)->valPtr;
	cout << "initial: *args = " << *valPtr << endl;
	
	for(int i = 1; i<=50000; i++)
	{
		(*valPtr)++;
	}
	cout << *valPtr << " ";
	pthread_exit(&(((Test *)args)->pid));//退出随便扔个状态码
}

void TestCase1(int &val)
{
	pthread_t pid1, pid2;
	Test test1,test2;

	test1.pid = pid1;
	test1.valPtr = &val;

	test2.pid = pid2;
	test2.valPtr = &val;

	pthread_attr_t attr;	//要想创建时加入参数，先声明 
	pthread_attr_init(&attr);	//再初始化
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//声明、初始化后第三步就是设置你想要指定线程属性参数，这个参数表明这个线程是可以join连接的，join功能表示主程序可以等线程结束后再去做某事，实现了主程序和线程同步功能，这个深层理解必须通过图示才能解释；参阅其他资料吧
	//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&pid1, &attr, add_val,(void *)&test1);
	pthread_create(&pid2, &attr, add_val, (void *)&test2);
	
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
}





