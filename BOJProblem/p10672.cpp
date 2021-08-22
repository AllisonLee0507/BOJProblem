#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main(void)
{
	int N; 
	cin >> N; 

	set<int> st; 
	vector<pair<int, pair<int, int>>> A; 

	for (int i = 0; i < N; i++)
	{
		int x, y, r; 
		cin >> x >> y >> r; 

		x += -r; 
		A.push_back(make_pair(y, make_pair(x - r, x))); 
		st.insert(x - r - 1); 
		st.insert(x - r); 
		st.insert(x - r + 1); 
		st.insert(x - 1);
		st.insert(x + 1); 
	}
	sort(A.begin(), A.end());

	int result = 0; 
	for (int i = 0; i < A.size(); i++)
	{
		auto it = st.lower_bound(A[i].second.first); 
		auto jt = st.lower_bound(A[i].second.second); 
		if (it != jt)
		{
			++result; 
			st.erase(it, jt); 
		}
	}
	cout << result << endl; 
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm> 
#include <queue>
#include <set>

using namespace std; 
struct str {
	int x, y, r, s, e; 
};

struct se {
	int s, e; 
};

bool operator <(str a, str b) 
{
	return a.y < b.y;
}
bool operator< (se a, se b)
{
	return a.e < b.e || a.e == b.e && a.s > b.s;
}

str inp[500005]; 
set <se> st;

int ans = 0; 
void func(set<se>::iterator &it, se &cur)
{
	int remember = it->s; 
	while (it != st.begin() && remember <= prev(it)->e)
	{
		remember = min(remember, prev(it)->s); 
		st.erase(prev(it)); 
	}
	cur.s = remember; 
	cur.e = it->e; 
	it = st.erase(it); 
	st.insert(cur); 
	it--; 
}
int main()
{
	int N; 
	scanf("%d", &N); 
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &inp[i].x, &inp[i].y, &inp[i].r); 
		inp[i].e = -inp[i].x * inp[i].r; 
		inp[i].s = inp[i].e - inp[i].r;
	}
	sort(inp, inp + N); 

	for (int i = 0; i < N; i++)
	{
		se cur = { inp[i].s, inp[i].e }; 
		auto it = st.lower_bound(cur); 
		if (it == st.end() || cur.s < it->s)
		{
			st.insert(cur); 
			ans++; 
			if (it == st.end())
			{
				it--; 
			}
			func(it, cur); 
			if (it != st.begin())
			{
				it--; 
			}
			func(it, cur); 
		}
	}
	printf("%d", ans); 
}

#endif 