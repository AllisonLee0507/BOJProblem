#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <algorithm>

using namespace std;

int lim[100];
int speed[100];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int sum = 0;
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        for(int j = sum; j<sum + a; j++){
            lim[j] = b;
        }
        sum += a;
    }
    sum = 0;
    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d%d", &a,&b);
        for(int j = sum; j<sum + a; j++){
            speed[j] = b;
        }
        sum += a;
    }
    int ans = 0;
    for(int i = 0; i<100; i++){
        ans = max(ans, speed[i] - lim[i]);
    }
    printf("%d", ans);
}
#endif
