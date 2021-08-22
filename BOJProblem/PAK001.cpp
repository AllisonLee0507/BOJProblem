#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int m, n, coin[10], ans = 987654321;

void solve(int mon, int d){
    if(mon > m){
        return;
    }
    if(mon == m){
        if (d<ans){
            ans = d;
            return;
        }
    }
    for (int i = 0; i <n; i++){
        solve(mon+coin[i], d+1);
    }
}
int main(){
    scanf("%d%d", &m, &n);
    for (int i = 0; i<n; i++){
        scanf("%d", coin + 1);
    }
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}

#endif
