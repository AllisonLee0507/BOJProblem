#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int X, Y, M;
    int usermin = 999999;
    int usermax = -999999;
    int count = 0;
    int S = 0, K = 0, A = 0, ans = 0;
    scanf("%d%d%d", &X, &Y, &M);
    
    usermin = min(X, Y);
    usermax = max(X, Y);
    count = M / X;
    S = M - (count * usermin);
    K = usermax - usermin;
    A = S/K;
    ans = (usermax * A) + (usermin * (count-A));
    printf("%d", ans);
}
#endif

#if 0
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int res = 0;
    for(int i = 0; x * i <= z; i++){
        int r = z - x*i;
        int h = x*i + r/y * y;
        res = max(res, h);
    }
    printf("%d", res);
}
#endif

#if 0
#include <iostream>
using namespace std;

bool dp[1001];
int a, b, x;
void go(int cur)
{
    if(cur > x)
    {
        return;
    }
    if(dp[cur])
    {
        return;
    }
    dp[cur] = true;
    go(cur + a);
    go(cur + b);
}
int main(){
    scanf("%d%d%d", &a, &b, &x);
    go(0);
    for(int i = x; i >= 0; i--)
    {
        if(dp[i])
        {
            
        }
    }
}
#endif
