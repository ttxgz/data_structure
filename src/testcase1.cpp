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
	pthread_exit(&(((Test *)args)->pid));//�˳�����Ӹ�״̬��
}

void TestCase1(int &val)
{
	pthread_t pid1, pid2;
	Test test1,test2;

	test1.pid = pid1;
	test1.valPtr = &val;

	test2.pid = pid2;
	test2.valPtr = &val;

	pthread_attr_t attr;	//Ҫ�봴��ʱ��������������� 
	pthread_attr_init(&attr);	//�ٳ�ʼ��
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//��������ʼ���������������������Ҫָ���߳����Բ��������������������߳��ǿ���join���ӵģ�join���ܱ�ʾ��������Ե��߳̽�������ȥ��ĳ�£�ʵ������������߳�ͬ�����ܣ�������������ͨ��ͼʾ���ܽ��ͣ������������ϰ�
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
	pthread_attr_destroy(&attr);//����ʹ�����˾Ϳ��������ˣ���������Ŷ����ֹ�ڴ�й¶��
}





