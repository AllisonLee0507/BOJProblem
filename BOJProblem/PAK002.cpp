#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int n, ans;
int state[2] = {1, 2};

void solve(int v){
    if(v>n){
        return;
    }
    if (v==n){
        ans++;
        return;
    }
    for (i =0; i<2; i++){
        solve(v+state[i]);
    }
}

int main(){
    scanf("%d", &n);
    solve(0);
    printf("%d\n", ans); 
}

#endif
