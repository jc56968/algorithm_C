#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
//动态规划：1.最优子结构。2.自底向上思考求解!=递归自顶而下
//for sample max_length_string
int dynamic_program()
{
	return 0;
}
string max_string(string A, string B)
{
	int n;
	n = A.size();
	int** C = new int* [n];

	for (int i = 0; i < n; i++)
		C[i] = new int[n];


	for (int i = 0; i <= n - 1; ++i)
	{
		for (int j = 0; j <= n - 1; ++j)
		{
			C[i][j] = 0;
		}

	}



	for (int i = 0; i < n; ++i)

		(B.find(A[i]) > 0) ? C[i][i] = 1 : C[i][i] = 0;

	string L;
	int ss;
	for (int i = 0; i < n; ++i)
	{
		int kk = 0;
		ss = i;
		for (int j = 0; j < n - ss; j++)
		{
			L.assign(A, kk, ss + 1);
			if (B.find(L) != 4294967295)//B.find(L) jisuanyouwu
				C[kk++][i++] = ss + 1;
			else
				C[kk++][i++] = 0;

		}
		i = i - (n - ss);
	}

	int MAX = 0;
	string AIM;
	for (int i = 0; i <= n - 1; ++i)
	{
		for (int j = 0; j <= n - 1; ++j)
		{
			if (C[i][j] > MAX)
			{

				MAX = C[i][j];
				AIM.assign(A, i, MAX);
			}

			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
	cout << MAX << "\n";
	cout << AIM;
	return AIM;


}
int main()
{
	string A = "fsfgwegaaabbbcccqwd";
	string B = "rgijgfwklfljasoigaufhawfdDaaabbbcccLWFMAIHFWRoioPOKJGVDZIKVZ264645f46s8f4768ffsjfnherukgseabfawfawefagaferge";
	max_string(A, B);
	return 0;
}



