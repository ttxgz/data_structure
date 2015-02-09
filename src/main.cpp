/*
* Purpose:
* Author: Wanming @ /12/2014
* Input Para:
* Output:
* Exe:
* Comment:
*/

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

//#define TESTCASE_1
#define TESTCASE_2

#define For(start,end) for(int cnt = start; cnt <= end; cnt++)
#define MAX(a,b) ((a) > (b) ? (a):(b))
#define MIN(x,y)   ((x)<(y)? (x):(y))

template <class T> inline void checkMax(T &a, T b) {if(b>a) a = b;}
template <class T> inline void checkMin(T &a, T b) {if(b<a) a = b;}


const string caseSeperate = "///////////////////////////////////////////////////////////////////////////////";


int main()
{

#ifdef TESTCASE_1
	{//TestCase 1: a simple case use socket
	const string debugStrCase1 = "TestCase 1: a simple case use socket";
	cout << endl << caseSeperate << endl << debugStrCase1 << endl << caseSeperate << endl;

	testcase1();	

	
	const string conclusionStrCase1 = "";
	cout << endl << "CONCLUSION: " << conclusionStrCase1 << endl;
	}//TestCase 1
#endif

#ifdef TESTCASE_2
	//TestCase 2: a[N-2] is consist of 1,...,N, without repeated number. Print the 2 lost number. No extra spase used
	const string debugStrCase2 = "TestCase 2: a[N-2] is consist of 1,...,N, without repetative number. Print the 2 lost number. No extra spase used";
	cout << endl << caseSeperate << endl << debugStrCase2 << endl << caseSeperate << endl;
	
		
	const string conclusionStrCase2 = "calc: a + b, a2 + b2, 2ab, then a-b, then done";
	cout << endl << "CONCLUSION: " << conclusionStrCase2 << endl;
#endif

	return 0;
}
