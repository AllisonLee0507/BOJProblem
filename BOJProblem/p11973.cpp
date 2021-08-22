#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, K, arr[50005];
int main() 
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    int lo = 1, hi = 1e9;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2, cur = 0, cnt = 0;
        bool possible = false;
        while (1)
        {
            int idx = lower_bound(arr, arr + N, arr[cur] + 2 * mid) - arr;
            if (idx >= N - 1)
            {
                possible = true;
                break;
            }
            if (arr[cur] + 2 * mid == arr[idx])
            {
                cur = idx + 1;
            }
            else
            {
                cur = idx;
            }
            cnt++;
            if (cnt == K)
            {
                break;
            }
        }
        if (possible) 
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    printf("%d", lo);
}
#endif 


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, k;
int arr[50000];

bool check(int val)
{
    int cur = 0, i = 0;

    while (i != n)
    {
        int j = i;
        while (j < n && arr[j] - arr[i] <= val)
        {
            j++;
        }
        cur++;
        i = j;
    }

    return cur <= k;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);

    int l = -1, r = 1e9 + 1;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (check(mid * 2))
        {
            r = mid;
        }

        else
        {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}

#endif 