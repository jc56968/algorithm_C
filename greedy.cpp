

//贪心算法：1.最优子结构。(父子问题相同200)2.自底向上思考求解!=递归自顶而下3.当前最优为全局最优
//greedy:1.
//for sample Dijkstra and min_generate_tree
#include<stdio.h>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
void min_generate_treeB(int  A[9][9])
{
	int B[9], C[9][9],N,I,J,c=1;
	vector<int> Q(9);
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			C[i][j] = 0;
	for (int i = 0; i < 9; ++i)
	{
		B[i] = 0;
		Q[i] = i;
	}

	Q.pop_back();
	while (!Q.empty())
	{
		N = 0;
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (A[i][j] != 0 && (B[i] != B[j]||(B[i] ==0&& B[j]==0)))
					if (A[i][j] <= N || N == 0)
					{
						N = A[i][j];
						I = i;
						J = j;
					}
			}
		}
		C[I][J] = A[I][J];
		A[I][J] = 0;
		if (B[I] == 0 && B[J] == 0)
		{
			B[I] = c;
			B[J] = c;
		}
		else if(B[I]==0||B[J]==0)
		{
			B[I] == 0 ? B[I] = B[J] : B[J] = B[I];
		}
		else if ((B[I] != 0 && B[J] != 0))
		{
			int aa, bb;
			aa = B[I];
			bb = B[J];
			for (int i = 0; i < 9; ++i)
			{
			
				if (B[i] == aa)
				{
					B[i] = c;
				}
				if (B[i] == bb)
				{
					B[i] = c;
				}
			}
		}

		c++;
	
		Q.pop_back();
	}
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{

			cout << C[i][j] << " ";

		}
		cout << "\n";
	}
	
}
void min_generate_treeA(int  A[9][9])
{//prim
	int B[9], N = 0, I, J, C[9][9] = {0};
	vector<int> Q(9);

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			C[i][j] = 0;
	for (int i = 0; i < 9; ++i)
	{
		B[i] = 0;
		Q[i] = i;
	}
	B[4] = 1;
	Q.pop_back();
	while (Q.empty() == 0)
	{
		N = 0;
		
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (A[i][j] != 0&&(B[i]==1||B[j]==1))
					if (A[i][j] <= N || N == 0)
					{
						N = A[i][j];
						I = i;
						J = j;
					}
			}
		}
		B[I] = 1;
		B[J] = 1;
		Q.pop_back();
		C[I][J] = A[I][J];
		A[I][J] = 0;
		

	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{

			cout << C[i][j] << " ";

		}
		cout << "\n";
	}

}

void Dijkstra(int  A[9][9])
{
	//A-D 0-3
	int B[9] ;
	int s,a=0,ss[9],su[9];
	vector <int> C;
	//vector <int>::iterator p = max_element(C.begin(), C.end());
	for (int i = 0; i < 9; i++)
		B[i] = 0, ss[i] = 0;

	C.push_back(a);
	ss[a] = 1;
	su[a] = 1;

	

	int* p;
	while (C.empty() != 1)
	{
		if (C.size() == 1)
		{
			
			vector<int>::iterator p = max_element(C.begin(), C.end());
			s =* p;
			C.erase(p);
			su[s] = 1;
		}
		else
		{
			int uu=1000;
			for(int i=0;i<9;i++)
				if (su[i]!=1&&B[i] != 0&&B[i]<=uu)
				{
					uu = B[i];
					s = i;
				}
		
			
			
			vector<int>::iterator u,k;
			for(u=C.begin();u!=C.end();u++)
				if (*u == s)
				{
					k = u;
				}
			C.erase(k);
			su[s] = 1;
		}
		

	
		for (int j = 0; j < 9; j++)
			if ((A[s][j])!=0)
			{
				if (B[s] + A[s][j] <= B[j]||B[j]==0)
					B[j]=A[s][j]+ B[s];
				if (ss[j] != 1)
					C.push_back(j), ss[j] = 1;
			}
		for (int i = 0; i < 9; i++)
			cout << B[i] << " ";
		cout << '\n';
	}

}


int main()
{
	
	int A[9][9] = { 0,10,0,0,0,11,0,0,0,
				0,0,18,0,0,0,16,0,12,
				0,0,0,22,0,0,0,0,8,
				0,0,0,0,0,0,0,0,0,
				0,0,0,20,0,0,0,7,0,
				0,0,0,0,26,0,17,0,0,
				0,0,0,24,0,0,0,19,0,
				0,0,0,16,0,0,0,0,0,
				0,0,0,21,0,0,0,0,0,
	};
	int B[9][9] = { 0,10,0,0,0,11,0,0,0,
				0,0,18,0,0,0,16,0,12,
				0,0,0,22,0,0,0,0,8,
				0,0,0,0,0,0,0,0,0,
				0,0,0,20,0,0,0,7,0,
				0,0,0,0,26,0,17,0,0,
				0,0,0,24,0,0,0,19,0,
				0,0,0,16,0,0,0,0,0,
				0,0,0,21,0,0,0,0,0,
	};

	for (int i = 0; i <9; ++i)
	{
		for (int j = 0; j <9; ++j)
		{
			
			cout << A[i][j] << " ";
			if (A[i][j] == 0)
				A[i][j] = 0;
		}
		cout << "\n";
	}
	
	//Dijkstra(A);
	min_generate_treeA(A);
	min_generate_treeB(B);
	
}






