#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100001; 

int N, Q; 
int road[maxn]; 

int main()
{
	cin >> N >> Q; 
	for (int i = 0; i < N; i++)
	{
		cin >> road[i]; 
	}
	sort(road, road + N); 

	for (int i = 0; i < Q;  i++)
	{
		int l, r;
		cin >> l >> r; 

		auto lt = lower_bound(road, road + N, l); 
		auto rt = lower_bound(road, road + N, r + 1); 

		cout << (rt - lt) << endl; 

	}
	return 0;

}
#endif