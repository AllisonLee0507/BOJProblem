#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
using namespace std;
int rank[50] = {0}, weight[50], height[50];
int main(){
    int i, j, N;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d %d", weight+i, height+i);
    }
    for(i = 0; i < N; i++){
        for(j = 0; j<N; j++){
            if((weight[i] < weight[j]) && (height[i] < height[j])){
                rank[i]++;
            }
        }
    }
    for(i = 0; i < N; i++){
        printf("%d ", rank[i]+1);
    }
    return 0;
}
#endif
