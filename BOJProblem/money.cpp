#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int B, n, act[23], res;

void f(int i, int sum){
    if(i == n+1){
        if(sum <= B && sum > res){
            res = sum;
        }
        return;
    }
    f(i+1, sum+act[i]);
    f(i+1, sum);
}
int main(){
    int i;
    scanf("%d %d", &B, &n);
    for(i=1; i<=n; i++){
        scanf("%d", &act[i]);
    }
    f(1,0);
    printf("%d", res);
    return 0;
}
#endif
