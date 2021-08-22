#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <stdio.h>

typedef long long LL;

LL conv(int a[3], LL b){
    return b * b * a[0] + b * a[1] + a[2];
}

int main(){
    int k, a, b[2][3], p[3];
    LL t;
    for(scanf("%d", &k); k-- > 0; ){
        for(int i = 0; i < 2; i++){
            scanf("%d", &a);
            b[i][0] = a/100;
            b[i][1] = a/10 % 10;
            b[i][2] = a % 10;
        }
        for(p[0] = p[1] = 10; t = (conv(b[0], p[0]) - conv(b[1], p[1])); ){
            if(t<0){
                p[0]++;
            }
            else{
                p[1]++;
            }
        }
        printf("%d %d\n", p[0], p[1]);
    }
}
#endif
