#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int a[10100]; 
int c; 
int h[10100];
void change(int &a, int &b)
{
	int o = a; 
	a = b; 
	b = o; 
}
int pop()
{
	int x = 1; 
	change(h[1], h[c]); 
	c--; 

	while (1)
	{
		if (x * 2 > c)
		{
			break;
		}
		if (x * 2 + 1 > c)
		{
			if (h[x] < h[x * 2])
			{
				break;
			}
			else
			{
				change(h[x], h[x * 2]);
				x *= 2;
			}
		}
		else
		{
			if (h[x] > h[x * 2] || h[x] > h[x * 2 + 1])
			{
				if (h[x * 2] > h[x * 2 + 1])
				{
					change(h[x], h[x * 2 + 1]); 
					x = x * 2 + 1; 
				}
				else
				{
					change(h[x], h[x * 2]); 
					x = x * 2; 
				}
			}
			else
			{
				break; 
			}
		}
	}
	return h[c + 1]; 
}
void push(int xx)
{
	int x;
	h[++c] = xx; 
	x = c; 
	while (1)
	{
		if (x == 1)
		{
			break; 
		}
		if (h[x] < h[x / 2])
		{
			change(h[x], h[x / 2]); 
			x /= 2; 
		}
		else
		{
			break; 
		}
	}
}
int main()
{
	int N, T, i, s, e, mid, ans, x; 

	scanf("%d %d", &N, &T); 
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]); 
	}
	s = 1; 
	e = N; 
	ans = N; 

	while (s <= e)
	{
		mid = (s + e) / 2; 
		c = 0;
		for (i = 1; i <= mid; i++)
		{
			push(a[i]); 
		}
		for (i = mid + 1; i <= N; i++)
		{
			x = pop(); 
			push(x + a[i]); 
		}
		int mx = 0; 
		for (i = 1; i <= c; i++)
		{
			if (mx < h[i])
			{
				mx = h[i]; 
			}
		}
		if (mx > T)
		{
			s = mid + 1; 
		}
		else
		{
			e = mid - 1;
			if (mid < ans)
			{
				ans = mid; 
			}
		}
	}

	printf("%d", ans); 

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int arr[20000]; 
pair<int, int> ran[20000]; 
priority_queue<int> pq; 

int main(void)
{
	int c, n, a, b, r, p, i; 
	scanf(" %d%d", &c, &n); 

	for (i = 0; i < c; i++)
	{
		scanf("%d", &arr[i]); 
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b); 
		ran[i] = { a, b }; 
	}
	sort(arr, arr + c); 
	sort(ran, ran + n); 

	r = p = 0; 

	for (i = 0; i < c; i++)
	{
		while (p < n && ran[p].first <= arr[i])
		{
			pq.push(-ran[p++].second); 
		}
		while(!pq.empty() && -pq.top() < arr[i])
		{
			pq.pop(); 
		}
		if (!pq.empty())
		{
			r++; 
			pq.pop(); 
		}
	}
	printf("%d", r); 
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

using namespace std;

typedef struct p
{
	int s, e; 
	bool operator< (const p& t)
	{
		return s < t.s; 
	}
}p;
int main(void)
{
	int n, m; 
	cin >> n >> m; 
	int a[20005], z = 1, ans = 0; 
	p b[20005]; 

	FOR(i, 1, n)
	{
		cin >> a[i];
	}
	FOR(i, 1, m)
	{
		cin >> b[i].s >> b[i].e; 
	}
	sort(a + 1, a + n + 1); 
	sort(b + 1, b + m + 1); 

	priority_queue <int> pq; 

	FOR(i, 1, n)
	{
		while (z <= m && b[z].s <= a[i])
		{
			pq.push(-b[z++].e); 
		}
		while (pq.size() && -pq.top() < a[i])
		{
			pq.pop(); 
		}
		if (pq.size())
		{
			ans++; 
			pq.pop(); 
		}
	}
	cout << ans << endl; 
	return 0;
}
#endif

