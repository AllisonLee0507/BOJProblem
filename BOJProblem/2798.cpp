#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, M, val[100], result;
    result = 0;
    scanf("%d %d", &N, &M);
    for( int i = 0; i < N; i++){
        scanf("%d", val + i);
    }
    for(int i = 0; i < N -2; i++){
        for(int j = 0; j < N -1; j++){
            for(int k = 0; k < N ; k++){
                int cost = val[i] + val[j] + val[k];
                if(cost<= M){
                    result = max(cost, result);
                }
            }
        }
    }
    printf("%d\n", result); 
}
#endif

//https://www.acmicpc.net/status?user_id=allisonlee&problem_id=2798&from_mine=1 i
