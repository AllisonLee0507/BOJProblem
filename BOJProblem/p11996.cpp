#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <cstring>

using namespace std;

long long sumn2(long long v)
{
	return v * (v + 1) * (2 * v + 1) / 6; 
}
//int max(long long a, long long b)
//{
//	if (a > b)
//	{
//		return (int)a; 
//	}
//	return (int)b; 
//}
int main(void)
{
	int N;
	cin >> N;
	vector <long long> A(N);
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		c = max(0ll, c + A[i] - 1);
	}
	for (int i = 0; ; i++)
	{
		if (c == 0)
		{
			rotate(A.begin(), A.begin() + i, A.begin() + N); 
			break; 
		}
		c = max(0ll, c + A[i] - 1); 
	}
	long long result = 0;
	for (int i = 0; i < N; i++)
	{
		result += sumn2(A[i] + c - 1) - sumn2(c - 1);
		c = max(0ll, c + A[i] - 1);
	}
	cout << result << endl;
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue> 

using namespace std;

int n; 
int arr[1000]; 

int main(void)
{
	scanf("%d", &n); 

	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
	}
	int min = 987654321; 

	queue<int> stk;

	for (int i = 0; i < n; i++)
	{
		int num = 0; 

		for (int j = 0; j < n; j++)
		{
			if (arr[(i - j + n) % n] == 0)
			{
				stk.push(i - j); 
			}
			else
			{
				int m = arr[(i - j + n) % n];
				while (!stk.empty() && m)
				{
					int tmp = stk.front(); 
					stk.pop();
					num += (tmp - (i - j)) * (tmp - (i - j)); 
					m--; 
				}
				if (m == 0)
				{
					stk.push(i - j); 
				}
				else if (m > 1)
				{
					num = 987654321; 
					break; 
				}
			}
		}
		if (num < min)
		{
			min = num; 
		}
	}
	printf("%d\n", min); 

	return 0;
}
#endif

