#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int W, n, i, j, w[102], v[102];
int max(int a, int b){return a>b ? a:b;}
int AAA(int i, int r){
    if(i==n+1){
        return 0;
    }
    else if(r<w[i]){
        return AAA(i+1, r);
    }
    else{
        return max(
                   AAA(i+1, r), AAA(i+1, r-w[i])+v[i]);
    }
    return 0;
}
int main(){
    int i;
    scanf("%d %d", &n, &W);
    for(i = 1; i<=n; i++){
        scanf("%d%d", &w[i], &v[i]);
    }
    printf("%d", AAA(1, W));
    return 0;
}
#endif
