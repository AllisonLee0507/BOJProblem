#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
#define F first
#define S second

using namespace std;


int n, mx, mn, c;
bool v[N];
pair<int, int> a[N];


int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++){
        scanf("%d %d", &a[i].F, &a[i].S);
    }
    sort(a, a + n);
    mx = a[0].S;
    for (i = 1; i < n; i++) {
        if (a[i].S < mx) {
            v[i] = 1;
        }
        else{
            mx = a[i].S;
        }
    }
    mn = a[n - 1].S;
    for (i = n - 2; i >= 0; i--) {
        if (a[i].S > mn) {
            v[i] = 1;
        }
        else {
            mn = a[i].S;
        }
    }
    for (i = 0; i < n; i++){
        c += !v[i];
    }
    cout << c << endl;
    return 0;
}
#endif
