#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    int a, b, c, d;
    int ans = 0;
    int min = 0x7fffffff, max = -0x7fffffff;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    
    if(c < b && a < d){
        if(a < c){
            min = a;
        }
        else{
            min = c;
        }
        if(b < d){
            max = d;
        }
        else{
            max = b;
        }
        ans = max - min;
    }
    else{
        ans = (b - a) + (c - d);
    }
    printf("%d\n", ans);
}

#endif
