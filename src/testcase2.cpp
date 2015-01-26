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
		pthread_mutex_lock (&val_mutex);//�޸�sum���ȼ���������ռ�þ�������ֱ���õ������޸�sum��
		(*valPtr)++;
		pthread_mutex_unlock (&val_mutex);//���º�������ͷŸ������߳�ʹ��;  
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

	pthread_mutex_init (&val_mutex, NULL);//����Ƕ������г�ʼ��������ģ�
	
	pthread_attr_t attr;	//Ҫ�봴��ʱ��������������� 
	pthread_attr_init(&attr);	//�ٳ�ʼ��
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//��������ʼ���������������������Ҫָ���߳����Բ��������������������߳��ǿ���join���ӵģ�join���ܱ�ʾ��������Ե��߳̽�������ȥ��ĳ�£�ʵ������������߳�ͬ�����ܣ�������������ͨ��ͼʾ���ܽ��ͣ������������ϰ�
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
	pthread_attr_destroy(&attr);//����ʹ�����˾Ϳ��������ˣ���������Ŷ����ֹ�ڴ�й¶��
	pthread_mutex_destroy(&val_mutex);
}





