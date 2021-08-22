#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int K; 
int MAP[14]; 
int Select_Num; 
bool Visit[14]; 

vector<int> V; 

void Init()
{
	V.clear(); 
	Select_Num = 6;
	memset(MAP, 0, sizeof(MAP)); 
	memset(Visit, false, sizeof(Visit)); 
}
void Print_num()
{
	sort(V.begin(), V.end()); 
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " "; 
	}
	cout << endl; 
}

void BFS(int Idx, int Cnt)
{
	if (Cnt == Select_Num)
	{
		Print_num(); 
		return; 
	}
	for (int i = Idx; i < K; i++)
	{
		if (Visit[i] == true)
		{
			continue; 
		}
		Visit[i] = true;
		V.push_back(MAP[i]); 
		BFS(i, Cnt + 1); 
		Visit[i] = false; 
		V.pop_back();
	}
}
void Solve()
{
	while (true)
	{
		Init(); 
		cin >> K; 
		if (K == 0)
		{
			break;
		}
		for (int i = 0; i < K; i++)
		{
			cin >> MAP[i]; 
		}
		BFS(0, 0);
		cout << endl; 
	}
}
int main(void)
{
	Solve(); 

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#define MAX_SIZE 13
using namespace std;

int lotto[MAX_SIZE]; 
int combi[MAX_SIZE];
int k; 

void dfs(int start, int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << combi[i] << ' ';
		}
		cout << endl; 
		return; 
	}
	for (int i = start; i < k; i++)
	{
		combi[depth] = lotto[i]; 
		dfs(i + 1, depth + 1); 
	}
}
int main(void)
{
	while (cin >> k && k)
	{
		for (int i = 0; i < k; i++)
		{
			cin >> lotto[i];
		}
		dfs(0, 0);

		cout << endl;
	}
	return 0;
}
#endif