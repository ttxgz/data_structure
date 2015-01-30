/*
* Purpose:
* Author: Wanming @ /12/2014
* Input Para:
* Output:
* Exe:
* Comment:
*/

//#include <stdio.h>
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include "testcase1.h"
#include "testcase2.h"
#include "testcase3.h"
#include "testcase4.h"


using namespace std;

//#define TESTCASE_1
//#define TESTCASE_2
//#define TESTCASE_3
#define TESTCASE_4


#define For(start,end) for(int cnt = start; cnt <= end; cnt++)
#define MAX(a,b) ((a) > (b) ? (a):(b))
#define MIN(x,y)   ((x)<(y)? (x):(y))

template <class T> inline void checkMax(T &a, T b) {if(b>a) a = b;}
template <class T> inline void checkMin(T &a, T b) {if(b<a) a = b;}


const string caseSeperate = "///////////////////////////////////////////////////////////////////////////////";


int main()
{

#ifdef TESTCASE_1
	//TestCase 1: 2 threads to access 1 variables, without mutual protection //
	const string debugStrCase1 = "TestCase 1: 2 threads to access 1 variables, without mutual protection";
	cout << endl << caseSeperate << endl << debugStrCase1 << endl << caseSeperate << endl;

	int val_1(0);
	TestCase1(val_1);
	cout << "val: " << val_1 << endl;

	const string conclusionStrCase1 = "without mutual protection, the val is [50000,100000] (run several times to verify)";
	cout << endl << "CONCLUSION: " << conclusionStrCase1 << endl;
#endif

#ifdef TESTCASE_2
		//TestCase 2: 2 threads to access 1 variables, with mutex (mutual exclusion) //
		const string debugStrCase2 = "TestCase 2: 2 threads to access 1 variables, with mutex (mutual exclusion)";
		cout << endl << caseSeperate << endl << debugStrCase2 << endl << caseSeperate << endl;

		int val_2(0);
		TestCase2(val_2);
		cout << "val: " << val_2 << endl;

		const string conclusionStrCase2 = "with mutex (mutual exclusion) , the val is always 100000(run several times to verify)";
		cout << endl << "CONCLUSION: " << conclusionStrCase2 << endl;
#endif

#ifdef TESTCASE_3
		//TestCase 3:
		const string debugStrCase3 = "TestCase 3: use semaphore, create 3 thread, to print A,B,C, and its thread id, the order should be: ABCABC";
		cout << endl << caseSeperate << endl << debugStrCase3 << endl << caseSeperate << endl;

		TestCase3();

		const string conclusionStrCase3 = "use 3 semaphore";
		cout << endl << "CONCLUSION: " << conclusionStrCase3 << endl;
#endif

#ifdef TESTCASE_4
		//TestCase 4:
		const string debugStrCase4 = "TestCase 4: 2 producer, 4 buffers, 4 consumer";
		cout << endl << caseSeperate << endl << debugStrCase4 << endl << caseSeperate << endl;

		TestCase4();

		const string conclusionStrCase4 = "using semaphore";
		cout << endl << "CONCLUSION: " << conclusionStrCase4 << endl;
#endif
#if 0
	while(1)
		;
#endif
	return 0;
}
