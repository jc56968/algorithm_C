

//贪心算法：1.最优子结构。(父子问题相同200)2.自底向上思考求解!=递归自顶而下3.当前最优为全局最优
//greedy:1.
//for sample Dijkstra and min_generate_tree
#include<stdio.h>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
void min_generate_tree()
{
	
	int a, b, c;
	char ccc, cc, c;
	int u, f, h;
	int ss;

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

	Dijkstra(A);
	
}






