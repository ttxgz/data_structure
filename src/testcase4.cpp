#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <fcntl.h>
#include <iomanip>
#include "testcase4.h"

using namespace std;

sem_t bufferFull;
sem_t bufferEmpty;
pthread_mutex_t mutexBuf[BUF_NUMBER];
pthread_mutex_t mutexWid;   //mutex for write id
pthread_mutex_t mutexRid;   //mutex for read id
int Buf[BUF_NUMBER];
int Wid;    //the write id
int Rid;    //the read id
int productNum; //how many products have been produced
bool finish;
bool finish_pro;

void* producer(void* args)
{
    int pro_id = *((int *)args);
    while(1)
    {
        sem_wait(&bufferEmpty);
        pthread_mutex_lock(&mutexWid);// read the Wid
        pthread_mutex_lock(&mutexBuf[Wid]);

        if(finish_pro)
        {
            cout << "all products have been produced, exit this thread" << endl;
            pthread_mutex_unlock(&mutexBuf[Wid]);
            pthread_mutex_unlock(&mutexWid);
            break;
        }
        int  sem_cnt;
        sem_getvalue(&bufferEmpty, &sem_cnt);
        //cout << "before produce " << productNum << " in buffer " << Wid << ", bufferEmpty = " << sem_cnt << endl;
        //produce product
        cout << "P" << pro_id << "put " << productNum << " in buffer " << Wid << endl;
        Buf[Wid] = productNum;
        productNum++;
        sem_post(&bufferFull);
        sem_getvalue(&bufferFull, &sem_cnt);
        if (productNum == MAX_PRODUCT_NUM + 1)
        {
            cout << "all products are produced!" << endl;
            finish_pro = true;
            cout << "unlock Buf[Wid] @" << Wid << endl;
            pthread_mutex_unlock(&mutexBuf[Wid]);
            pthread_mutex_unlock(&mutexWid);
            cout << "break@" <<__LINE__ << endl;
            break;
        }
        pthread_mutex_unlock(&mutexBuf[Wid]);
        Wid = (Wid + 1)%BUF_NUMBER;
        pthread_mutex_unlock(&mutexWid);
    }
}

void* consumer(void* args)
{
    int con_id = *((int *)args);
    cout << "new consumer thread C" << pthread_self() << endl;
    while(1)
    {
        sem_wait(&bufferFull);
        int  sem_cnt;
        pthread_mutex_lock(&mutexRid);// read the Wid
        pthread_mutex_lock(&mutexBuf[Rid]);
        sem_getvalue(&bufferFull, &sem_cnt);
        //cout << "before fetch " << " buffer " << Rid << ", bufferFull= " << sem_cnt << endl;
        if(finish)
        {
            cout << "all products have been picked, finish this consumer thread" << endl;
            cout << "unlock Buf[Rid] @" << Rid << endl;
            pthread_mutex_unlock(&mutexBuf[Rid]);
            pthread_mutex_unlock(&mutexRid);
            break;
        }
        //consume product
        cout << "C" << con_id << "fetch " << Buf[Rid] << "in buffer " << Rid << endl;
        if(Buf[Rid] == MAX_PRODUCT_NUM)
        {
            //let all other consumer exit
            cout << "pick up the last product" << endl;
            finish = true;
            sem_post(&bufferEmpty);
            //cout << "unlock Buf[Rid] @" << Rid << endl;
            //important here! to let other consumer thread to enter the sem_wait to exit
            for(int cnt = 0; cnt <= CONSUMER_NUM - 2; cnt++)
            {
                cout << "post bufferFull" << endl;
                sem_post(&bufferFull);
            }
            pthread_mutex_unlock(&mutexBuf[Rid]);
            pthread_mutex_unlock(&mutexRid);
            break;
        }
        sem_post(&bufferEmpty);
        sem_getvalue(&bufferEmpty, &sem_cnt);
        //cout << "after fetch " << ", bufferEmpty = " << sem_cnt << endl;
        pthread_mutex_unlock(&mutexBuf[Rid]);
        Rid = (Rid + 1)%BUF_NUMBER;
        pthread_mutex_unlock(&mutexRid);
    }
    cout << __LINE__ << endl;
}

void TestCase4()
{
    //initial
    productNum = 0;
    finish = false;
    finish_pro = false;
    Wid = 0;
    Rid = 0;
	if(sem_init(&bufferEmpty,0,BUF_NUMBER) != 0)
    {
        cout << "err when init semaphore!" << endl;
    }
	if(sem_init(&bufferFull,0,0) != 0)
    {
        cout << "err when init semaphore!" << endl;
    }
    pthread_mutex_init(&mutexWid,NULL);
    pthread_mutex_init(&mutexRid,NULL);
    for(int cnt = 0; cnt < BUF_NUMBER;cnt++)
        pthread_mutex_init(&mutexBuf[cnt],NULL);

	pthread_t pid[PRODUCER_NUM + CONSUMER_NUM];

	pthread_attr_t attr;	//Ҫ?봴??ʱ????????????????
	pthread_attr_init(&attr);	//?ٳ?ʼ??
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//???����?ʼ??????????????????????Ҫָ???߳????Բ??????????????????????߳??ǿ???join��?ӵģ?join???ܱ?ʾ?????????Ե??߳̽???????ȥ??ĳ?£?ʵ?????????????߳?ͬ?????ܣ?????????????????ͨ??ͼʾ???ܽ??ͣ????????????ϰ?

    for(int cnt = 0; cnt < PRODUCER_NUM; cnt++)
    {
        int pro_id = cnt;
	    pthread_create(&pid[cnt], &attr, producer, &pro_id);
    }
    for(int cnt = PRODUCER_NUM; cnt < PRODUCER_NUM + CONSUMER_NUM; cnt++)
    {
        int con_id = cnt;
	    pthread_create(&pid[cnt], &attr, consumer, &con_id);
    }

	void *status;
    for(int cnt = 0; cnt < PRODUCER_NUM + CONSUMER_NUM; cnt++)
    {
	    int ret = pthread_join(pid[cnt], &status);
	    if (ret != 0)
        {
            cout << "pthread_join error: error_code=" << ret << endl;
        }
        else
        {
            cout << "pthread_" << cnt << " join get status: " << (long)status << endl;
        }
    }

    cout << __LINE__ << endl;
	pthread_attr_destroy(&attr);//????ʹ?????˾Ϳ????????ˣ?????????Ŷ????ֹ?ڴ?й¶?

	sem_destroy(&bufferFull);
	sem_destroy(&bufferEmpty);
    pthread_mutex_destroy(&mutexWid);
    pthread_mutex_destroy(&mutexRid);
    for(int cnt = 0; cnt < BUF_NUMBER;cnt++)
        pthread_mutex_destroy(&mutexBuf[cnt]);
}





