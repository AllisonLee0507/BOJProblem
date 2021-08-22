#define _CRT_SECURE_NO_WARNINGS
//#if 0
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int N;
//    scanf("%d", &N);
//    int a[N];
//
//    for(int i = 0; i < N; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    sort(a, a+N);
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            if(a[i] - 1 <= a[j] && a[j] <= a[i]+1)
//            {
//
//            }
//        }
//
//
//    }
//}
//#endif

#if 0
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[101];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    sort(a, a+n);
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        int l = i, r = i, cnt = 1;
        while(1)
        {
            int tl = lower_bound(a, a + n, a[l] - cnt)- a;
            if(tl == l)
            {
                break;
            }
            l = tl;
            cnt++;
        }
        cnt = 1;
        while(1)
        {
            int tr = lower_bound(a, a+n, a[r] +cnt)-a;
            if(tr>=n || a[tr] > a[r]+cnt)
            {
                tr--;
            }
            if(tr == r)
            {
                break;
            }
            r = tr;
            cnt ++;
        }
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0 ;
}
#endif
