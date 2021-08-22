#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#define MAXV 9999999

int M, n, i, m[101], c[101];
int min(int a, int b){
    return a<b? a:b;
}
int f(int i, int r){
    if(i==0){
        if(r<=0){
            return 0;
        }
        else{
            return MAXV;
        }
    }
    else if(r<0){
        return f(i-1, r);
    }
    else{
        return min(f(i-1, r), f(i-1, r-m[i])+c[i]);
    }
}
int main(){
    scanf("%d %d", &n, &M);
    for(i = 1; i <= n; i++){
        scanf("%d", &m[i]);
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    printf("%d", f(n, M));
    return 0;
}
#endif
