#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int h[10], sum;
    sum = 0;
    for(int i = 0; i < 9; i++){
        scanf("%d", &h[i]);
        sum  = sum + h[i];
    }
    sort(h, h+10);
    
    for(int i = 0; i < 9; i++){
        for(int j = i +1; j<9; j++){
            if(sum - h[i] - h[j] == 100){
                for(int k = 0; k < 9; k++){
                    if(k == i || k == j){
                        continue;
                    }
                    printf("%d\n", h[k]); 
                }
            }
        }
    }
    
}
#endif

//https://www.acmicpc.net/status?user_id=allisonlee&problem_id=2309&from_mine=1
