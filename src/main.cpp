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
	{//TestCase 1: a[N+M] is consist of number 1,...N, please output the repeated number. No extra space, O(M+N)
	const string debugStrCase1 = "TestCase 1: a[N+M] is consist of number 1,...N, please output the repeated number. No extra space, O(M+N)";
	cout << endl << caseSeperate << endl << debugStrCase1 << endl << caseSeperate << endl;

	/* pseudo code:
	from a[0] to a[N+M-1]
	{
		while ((a[i] != i + 1) && (a[i] != -1) 
		{
			//exchange a[a[i] -1] and a[i] 
			int index = a[i] -1;
			if(a[index] == a[i])
			{
				a[i] = -1;
				output a[i];
			}
			else //put the ball into the basket
			{
				set a[i] = a[index];
				set a[index] = index + 1;
			}
		}
	}
	print a[N] to a[N+M-1]

	{
                while (A[i] != i + 1 && A[i] != -1)
                {
                    int index = A[i] - 1;
                    if (A[index] == A[i])
                    {
                        A[i] = -1;
                        Console.WriteLine(A[index]);
                    }
                    else
                    {
                        A[i] = A[index];
                        A[index] = index + 1;
                    }
                }
            }

            
	*/
	int N,M;
	
	cout << " N = "; cin >> N;
	cout << " M = "; cin >> M;

	int* array = new int[N+M];

	cout << "please enter N + M numbers, choose from 1 to N, use Enter to seperate" << endl;

	int inCnt(0);
	while(inCnt < N+M)
	{
		cin >> array[inCnt++];
	}

	for(inCnt = 0; inCnt < N+M; inCnt++)
	{
		// when the ball in basket[inCnt] is not ball number inCnt + 1, change until the right number ball in it 
		while((array[inCnt] != inCnt + 1) && (array[inCnt] != -1) && (array[inCnt] != -2))
		{
			int index = array[inCnt] - 1;
			//the target ball is correct, exchange finish and output the repeated number
			if((array[index] == index + 1) ||(array[index] == -2))
			{
				array[inCnt] = -1;
				if(array[index] != -2)
				{
					cout << "find repeated number: " << index + 1 << " " << endl;
					array[index] = -2;
				}
			}
			//exchange the ball to the correct place
			else
			{
				array[inCnt] = array[index];
				array[index] = index + 1;
			}
			
			cout << inCnt << ": [";
			{
				for(int i(0); i < N+M; i++)
					cout << array[i] << " ";
			}
			cout << "]" << endl;
		}
	}

	
	delete[] array; 
	
	

	
	const string conclusionStrCase1 = "kinds of counting sort";
	cout << endl << "CONCLUSION: " << conclusionStrCase1 << endl;
	}//TestCase 1
#endif

#ifdef TESTCASE_2
	//TestCase 2: a[N-2] is consist of 1,...,N, without repeated number. Print the 2 lost number. No extra spase used
	const string debugStrCase2 = "TestCase 2: a[N-2] is consist of 1,...,N, without repetative number. Print the 2 lost number. No extra spase used";
	cout << endl << caseSeperate << endl << debugStrCase2 << endl << caseSeperate << endl;
	
	int N;
	
	cout << " N = "; cin >> N;
	
	int* array = new int[N-2];

	cout << "please enter N - 2 numbers, choose from 1 to N, no repeated number, use Enter to seperate" << endl;

	int inCnt(0);
	while(inCnt < N-2)
	{
		cin >> array[inCnt++];
	}
	
	cout << "input array is: [";
	for(int cnt = 0; cnt < N-2; cnt++)
		cout << array[cnt] << ",";
	cout << "]" << endl;

	/*
		sum = 1 + 2 + ... + N = N*(N+1)/2
		squareSum = 1*1 + 2*2 + ... + N*N = N*(N+1)*(2N+1)/6
		mul = N!
		
		sum = a + b
		squareSum = a*a + b*b
		mul = 2ab
	*/
	int sum = N*(N+1)>>1;
	int squareSum = sum*(2*N + 1)/3;
	int mul(1);

	for(int cnt = 1; cnt <= N; cnt++)
	{
		mul = mul*cnt;
	}

	for(int cnt = 0; cnt < N - 2; cnt++)
	{
		sum -= array[cnt];						// a+b
		squareSum -= array[cnt]*array[cnt];		//a*a + b*b
		mul = mul/array[cnt];					//a*b
	}

	int difference = sqrt(squareSum - 2*mul);	// |a - b|

	cout << " two missing number is: " << ((sum + difference)>>1) << ", " << ((sum - difference)>>1) << endl;
	
	delete[] array;
	
	const string conclusionStrCase2 = "calc: a + b, a2 + b2, 2ab, then a-b, then done";
	cout << endl << "CONCLUSION: " << conclusionStrCase2 << endl;
#endif

	return 0;
}
