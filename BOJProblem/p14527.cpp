#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


typedef std::pair<int, int> ii;

int N;
ii D[100'004];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> D[i].second >> D[i].first;
	}
	sort(D, D + N);

	int ans = 0;
	int li = 0, ln = 1;
	int ri = N - 1, rn = D[N - 1].second;
	do {
		ans = max(ans, D[li].first + D[ri].first);
		const int mv = min(D[li].second - ln + 1, rn);
		ln += mv;
		rn -= mv;
		if (D[li].second < ln)
		{ 
			++li; 
			ln = 1; 
		}
		if (rn <= 0) 
		{ 
			--ri; 
			rn = D[ri].second;
		}
	} 
	while (li < ri || (li == ri && ln < rn));

	cout << ans << endl;
	return 0;
}

#endif