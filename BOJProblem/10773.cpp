#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;
int main(){
    int K, N;
    stack <int> S;
    scanf("%d", &K);
    for(int i = 0; i<K; i++){
        scanf("%d", &N);
        if(N){
            S.push(N);
        }
        else{
            S.pop();
        }
        long long sum = 0;
        while(!S.empty()){
            sum += S.top();
            S.pop();
        }
        printf("%lld\n", sum);
    }
}
#endif

//STL
#if 0
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    int K, N;
    stack<int> S;
    scanf("%d", &K);
    for(int i = 0; i<K; i++){
        scanf("%d", &N);
        if(N){
            S.push(N);
        }
        else{
            S.pop();
        }
    }
    long long sum = 0;
    while(!S.empty()){
        sum += S.top();
        S.pop();
    }
    printf("%lld\n", sum);
}
#endif
