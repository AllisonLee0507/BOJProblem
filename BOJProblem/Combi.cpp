#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 9
using namespace std;
int N, M;
bool Visit[MAX];
vector<int> V;

void Input(){
    cin >> N >> M;
}
void DFS(int Cnt){
    if(Cnt == M){
        for(int i = 0; i < V.size(); i++){
            cout << V[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= N; i++){
        if(Visit[i] == true){
            continue;
        }
        Visit[i] =  true;
        V.push_back(i);
        DFS(Cnt + 1);
        Visit[i] = false;
        V.pop_back();
    }
}
void Solution(){
    DFS(0);
}
void Solve(){
    Input();
    Solution();
}
int main(void){
    Solve();
}
#endif

#if 0
#include <stdio.h>
int n, m, v[9];
char s[16];
void recur(int k){
    int i;
    if(k == m){
        puts(s);
        return;
    }
    for(i = 1; i <= n; i++){
        if(!v[i]){
            v[i] = 1;
            s[k*2] = i + '0';
            recur(k+1);
            v[i] = 0;
        }
    }
}
int main(){
    for(n = 0; n < 15; n++){
        s[n] = ' ';
    }
    scanf("%d%d", &n, &m);
    s[m*2 - 1] = 0;
    recur(0);
}
#endif
