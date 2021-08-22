#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int a, b;
int res = 40;
int state[6] = {10, 5, 1, -10, -5, -1};

void f(int temp, int cnt){
    if(cnt>res){
        return;
    }
    if (temp == b){
        if(cnt<res){
            res = cnt;
            return;
        }
    }
    for(int i = 0; i<6; i++){
        f(temp+state[i], cnt+1);
    }
}
int main(){
    scanf("%d%d", &a, &b);
    f(a,0);
    printf("%d", res);
    return 0;
}
#endif

