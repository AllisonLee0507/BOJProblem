#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int N;
    int ans1, ans2, a, b;
    ans1 = 0;
    ans2 = 0;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d%d", &a, &b);
        if(a==1&&b==2||a==2&b==3||a==3&&b==1){
            ans1++;
        }
        if(a==2&&b==1||a==3&b==2||a==1&&b==3){
            ans2++;
        }
    }
    if(ans1 > ans2){
        printf("%d", ans1);
    }
    else{
        printf("%d", ans2);
    }
}
#endif

