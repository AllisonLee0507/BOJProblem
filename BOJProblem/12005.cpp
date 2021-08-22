#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int a[1000];
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; ++i)
    {
        scanf("%d", a+i);
    }
    sort(a, a+n);
    int ans = 0;
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if(a[i] - a[j] <= k)
        {
            ans = max(ans, i-j+1);
            i++;
        }
        else
        {
            j++;
        }
    }
    printf("%d\n", ans);
}
#endif
