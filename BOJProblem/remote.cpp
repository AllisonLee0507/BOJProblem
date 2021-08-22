#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdlib.h>
#include <stdio.h>
int a;
int b;
int res = 40;
int state[3] = {10, 5, 1};
void f(int temp, int cnt){
    if(cnt>res){
        return;
    }
    if(temp==b){
        if(cnt<res){
            res = cnt;
            return;
        }
    }
    if(temp<b){
        for(int i = 0; i<3; i++){
            f(temp+state[i], cnt+1);
        }

    }
    else{
        for(int i = 0; i<3; i++){
            f(temp-state[i], cnt+1);
        }
    }
}
int main(){
    scanf("%d%d", &a, &b);
    f(a, 0);
    printf("%d", res);
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct ELE{int v, cnt;};
queue<ELE> Q;

int main(){
    int a, b, i;
    ELE temp;
    scanf("%d %d", &a, &b);
    Q.push({a, 0});
    while(!Q.empty()){
        temp=Q.front();
        Q.pop();
        if(temp.v == b){
            break;
        }
        if(temp.v < b){
            Q.push({temp.v+10, temp.cnt+1});
            Q.push({temp.v+5, temp.cnt+1});
            Q.push({temp.v+1, temp.cnt+1});
        }
        else{
            Q.push({temp.v-10, temp.cnt+1});
            Q.push({temp.v-5, temp.cnt+1});
            Q.push({temp.v-1, temp.cnt+1});
        }
    }
    printf("%d", temp.cnt);
}
#endif
