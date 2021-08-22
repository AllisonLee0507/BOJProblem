#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdlib.h>
#include <stdio.h>

int n, ans;
void solve(int v){
    if(v>n){
        return;
    }
    if(v==n){
        ans++;
        return;
    }
    for(int i = 1; i  <=2; i++)
    {
        solve(v+i);
    }
}
int main(){
    scanf("%d", &n);
    solve(0);
    printf("%d\n", ans);
}
#endif



#if 0
#include <stdlib.h>
#include <stdio.h>
int state[2]={1, 2};
int n, ans;
void solve(int v){
    if(v>n){
        return;
    }
    if(v==n){
        ans++;
        return;
    }
    for(int i = 0; i < 2; i++)
    {
        solve(v+state[i]);
    }
}
int main(){
    scanf("%d", &n);
    solve(0);
    printf("%d\n", ans);
}
#endif
