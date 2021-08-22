#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, K;
    int i;
    int a, b;

    cin >> N >> K;
    int count[N];
    for(i = 0; i <= N; i++){
        count[i] = 0;
    }
    
    for(i = 0; i < K; i++){
        cin >> a >> b;
        count[a] ++;
        count[b+1]--;
    }
    for(i = 0; i <= N; i++){
        cout << count[i] << ' ';
    }
    sort(count+1, count+7);
    
    cout << count[3];
        
        
}
#endif
