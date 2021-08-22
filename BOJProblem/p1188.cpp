#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int N, M, result, pos;
    result = pos = 0;
    scanf("%d %d", &N, &M);
    for(int i=1; i<M; i++){
        pos += N;
        if(pos%M) result++;
    }
    printf("%d\n", result);
}
#endif

#if 0
#include <iostream>
using namespace std;

int main(){
    int N, M, result, pos;
    result = pos = 0;
    cin >> N >> M;
    for(int i=1; i<M; i++){
        pos += N;
        if(pos%M) result++;
    }
    cout << result << endl;
}
#endif
