#if 0
#define _CRT_SECURE_NO_WARNINGS
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

int main()
{

    int c, n, a, b, r, p, i;
    scanf("%d%d", &c, &n);
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
        while (!pq.empty() && -pq.top() < arr[i])
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