#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int m, n, coin[10], ans = 987654321;
void solve(int mon, int d)
{
    if(mon > m){
        return;
    }
    if(mon == m){
        if(d > ans){
            ans = d;
            return;
        }
    }
    for(int i = 0; i < n; i++){
        solve(mon+coin[i],d+1);
    }
//    solve(mon+10,d+1);
//    solve(mon+50,d+1);
//    solve(mon+100,d+1);
//    solve(mon+500,d+1);
//    solve(mon+1250,d+1);
}
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i< n; i++){
        scanf("%d", coin + i);
    }
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}
#endif

#if 0
#include <stdio.h>
int m, n, coin[10], ans = 987654321;
void solve(int mon, int k, int cnt)
{
    if(k == n || mon > m){
        return;
    }
    if(mon == m){
        if(ans > cnt){
            ans = cnt;
            return;
        }
    }
    for(int i = 0; i < n; i++){
        solve(mon+coin[k]*i,k + 1, cnt + i);
    }
}
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i< n; i++){
        scanf("%d", coin + i);
    }
    solve(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
#endif
