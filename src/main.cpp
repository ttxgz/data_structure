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
#include <string.h>

using namespace std;

#define DEBUG
#define TESTCASE_1
//#define TESTCASE_2

#define For(start,end) for(int cntForLoop = (start); cntForLoop <= (end); cntForLoop++)
#define MAX(a,b) ((a) > (b) ? (a):(b))
#define MIN(x,y)   ((x)<(y)? (x):(y))
//#define P_LINE cout << "line " << __LINE__ << endl
#define P_LINE 


template <class T> inline void checkMax(T &a, T b) {if(b>a) a = b;}
template <class T> inline void checkMin(T &a, T b) {if(b<a) a = b;}


const string caseSeperate = "///////////////////////////////////////////////////////////////////////////////";


int main()
{

#ifdef TESTCASE_1
	{//TestCase 1: Manacher: A simple linear time algorithm for finding longest palindrome sub-string
	const string debugStrCase1 = "Manacher, O(n): A simple linear time algorithm for finding longest palindrome sub-string";
	cout << endl << caseSeperate << endl << debugStrCase1 << endl << caseSeperate << endl;

	/* pseudo code:
	http://blog.csdn.net/ggggiqnypgjg/article/details/6645824
	
	int manacher(int n) {
	22
		int mx = 0; //记录前面回文串最长影响到的地方。不一定是最长回文串造成的。
	23
		int id; //最长影响串的ID;
	24
		p[0] = 0;
	25
		int i;
	26
		int ans = 0;
	27
		for (i = 1; i < n; i++) {
	28
			p[i] = 1;
	29
			if (mx > i) { //2*id-i是i关于id的对称点相当于是id-(i-id);
	30
				p[i] = p[2 * id - i];
	31
	 
	32
				//由于对称点的回文半径可能超过mx-i,因为mx后面的还没有配过
	33
				//所以要取小的。等等继续配
	34
				if (mx - i < p[i])
	35
					p[i] = mx - i;
	36
			}
	37
			while (str[i - p[i]] == str[i + p[i]])
	38
				p[i]++;
	39
			if (i + p[i] > mx) {
	40
				mx = i + p[i];
	41
				id = i;
	42
			}
	43
			if (ans < p[i])
	44
				ans = p[i];
	45
		}
	46
	 
	47
		return ans;
	48
	}

            
	*/
	string inputStr;
	cout << "please input a string, no longer than 200" << endl; 
	cin >> inputStr;
#ifdef DEBUG
	cout << "input is: " << inputStr << endl;
#endif

	// STEP 1: add '#' in between string, to tackle odd/even length palindrome string
	char *insertStr = new char[inputStr.length()*2 + 2];

	insertStr[0] = '$';
	insertStr[1] = '#';
	For(0,inputStr.length() - 1)
	{
		insertStr[(cntForLoop<<1) + 2] = inputStr[cntForLoop];
		insertStr[(cntForLoop<<1) + 3] = '#';
	}
	insertStr[inputStr.length()*2 + 2] = 0; //inputStr[inputStr.length()]; //Great Important to end the string!!!!!!
#ifdef DEBUG
	cout << "after insert '#', the array is: " << insertStr << endl;
#endif

	//STEP 2: manacher
	int mx(0); // record the longest element that is palindrome. 记录前面回文串最长影响到的地方。不一定是最长回文串造成的。
	int centralMx(1);
	int longest(1);
	int centralLongest(0);
	int *len = new int[inputStr.length()*2 + 2];
	int centralNumber(0);

	len[0] = 1;
	For(1,inputStr.length()*2 + 1)
	{
		if(mx > cntForLoop)
		{
			P_LINE;
			len[cntForLoop] = MIN(len[centralMx - (cntForLoop - centralMx)],len[centralMx] + centralMx - cntForLoop);
		}
		else
		{
			len[cntForLoop] = 1;
		}
		
			while(insertStr[cntForLoop - len[cntForLoop]] == insertStr[cntForLoop + len[cntForLoop]])
			{
				len[cntForLoop]++;
				if(len[cntForLoop] + cntForLoop == inputStr.length()*2 + 2) //end of the string
					break;
				P_LINE;
			}
			if((centralLongest < len[cntForLoop]) && len[cntForLoop] > 2)
			{
				P_LINE;
				longest = len[cntForLoop];
				centralLongest = cntForLoop;
			}
			P_LINE;
			if(mx < cntForLoop + len[cntForLoop] - 1)
			{
				mx = cntForLoop + len[cntForLoop] - 1;
				centralMx = cntForLoop;
			}
		
	}

	cout << "len[]: ";
	For(0,inputStr.length()*2 + 1)
		cout << len[cntForLoop] << " " ;
	cout << endl;
	//DONE
	if(centralLongest != 0)
	{
		cout << "The longest palindrome substring is: " << centralLongest << "," << longest << endl;
		For(centralLongest - longest + 1, centralLongest + longest - 1)
		{
			cntForLoop++;
			if(cntForLoop < centralLongest + longest - 1)
				cout << insertStr[cntForLoop];
		}
		cout << endl;
	}
	else
		cout << "There is no palindrome substring" << endl;
	delete[] len; 
	delete[] insertStr;
	

	
	const string conclusionStrCase1 = "manacher";
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
