#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef long long LL; 

int main(void)
{
	int n; 
	cin >> n; 
	vector<int> a(n); 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; 
	}
	LL s = 0; 
	LL p = 0; 
	LL q = 1; 
	LL x = a.back(); 

	vector<int> k; 

	for (int i = n; i-- > 1; )
	{
		s += a[i]; 
		x = min(x, (LL)a[i]); 
		if (n - i > 1)
		{
			if (p * (n - i - 1) < q * (s - x))
			{
				p = s - x; 
				q = n - i - 1; 
				k = { i }; 
			}
			else if (p * (n - i - 1) == q * (s - x))
			{
				k.push_back(i); 
			}
		}
	}
	for (int i = k.size(); i-- > 0; i )
	{
		cout << k[i] << endl;
	}

	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	LL s = 0, p = 0, q = 1, x = a.back();
	vector<int> k;
	for (int i = n; i-- > 1; ) {
		s += a[i];
		x = min(x, (LL)a[i]);
		if (n - i > 1) {
			if (p * (n - i - 1) < q * (s - x)) p = s - x, q = n - i - 1, k = { i };
			else if (p * (n - i - 1) == q * (s - x)) k.push_back(i);
		}
	}
	for (int i = k.size(); i-- > 0; ) cout << k[i] << '\n';

	return 0;
}

#endif

#if 0
#include <cstdio>
#include <iostream>

using namespace std; 

void fillPrefixSum(int arr[], int n, int prefixSum[])
{
	prefixSum[0] = arr[0]; 

	for (int i = 1; i < n; i++)
	{
		prefixSum[i] = prefixSum[i - 1] + arr[i]; 
	}
}

int main()
{
	int arr[] = { 10, 4, 16, 20 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	int *prefixSum;
	//prefixSum = (int*)malloc(sizeof(int) * n);
	prefixSum = new int[n];

	fillPrefixSum(arr, n, prefixSum); 

	for (int i = 0; i < n; i++)
	{
		cout << prefixSum[i] << " "; 
	}
	//free(prefixSum);
	delete[] prefixSum;
}
#endif 

#if 0
#include<iostream>

using namespace std; 
const int N = 1e5 + 10; 
int a[N]; 
int pf[N]; 
int main() {
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; 
		pf[i] = pf[i - 1] + a[i]; 
	}
	int q;
	cin >> q; 
	while (q--)
	{
		int l, r; 
		cin >> l >> r; 
		cout << pf[r] - pf[l - 1] << endl; 
	}
}
#endif 

#if 0
#include <iostream>
#include <vector>

using namespace std; 
int find(int m, vector<pair<int, int>> q)
{
	int mx = 0; 
	vector<int> pre(5, 0); 

	for (int i = 0; i < m; i++)
	{
		int a = q[i].first, b = q[i].second; 

		pre[a - 1] += 100; 
		pre[b] -= 100; 
	}
	for (int i = 1; i < 5; i++)
	{
		pre[i] += pre[i - 1]; 
		mx = max(mx, pre[i]); 
	}
	return mx;
}
int main()
{
	int m = 3; 
	vector<pair<int, int>> q = { {2,4}, {1,3}, {1,2} }; 

	cout << find(m, q); 
	return 0; 
}
#endif 