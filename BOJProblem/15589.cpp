#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
typedef pair<int, int> pii; 
pii A[100010]; 
int sum; 
int ans = 2e9; 
int main(void)
{
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i].first >> A[i].second; 
	}
	sort(A + 1, A + n + 1); 
	for (int i = 1, r, l = -1; i <= n; i++)
	{
		int s = 0, e = 0; 
		tie(s, e) = A[i]; 

		sum += max(e - max(s, l), 0); 
		r = (i == n ? e : min(e, A[i + 1].first)); 
		l = max(l, s); 
		ans = min(ans, max((r - l), 0)); 
		l = max(l, e); 
	}
	cout << sum - ans; 
	return 0;
}
#endif