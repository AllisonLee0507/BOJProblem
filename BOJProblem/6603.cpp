#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define endl "\n"
#define MAX 13
using namespace std;
int K, Select_Num;
int MAP[MAX];
bool Visit[MAX];

vector<int> V;

void Intialize(){
    V.clear();
    Select_Num = 6;
    memset(MAP, 0, sizeof(MAP));
    memset(Visit, false, sizeof(Visit));
}
void Input(){
    for(int i = 0; i < K; i++){
        cin >> MAP[i];
    }
}
void Print_Number(){
    sort(V.begin(), V.end());
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
    }
    cout << endl;
}
void Select(int Idx, int Cnt){
    if(Cnt == Select_Num){
        Print_Number();
        return;
    }
    
    for(int i = Idx; i < K; i++){
        if(Visit[i] == true){
            continue;
        }
        Visit[i] = true;
        V.push_back(MAP[i]);
        Select(i, Cnt + 1);
        Visit[i] = false;
        V.pop_back();
    }
}
void Solution(){
    Select(0,0);
}
void Solve(){
    while(1){
        Intialize();
        cin >> K ;
        if(K == 0){
            break;
        }
        Input();
        Solution();
        cout << endl;
        
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    
    return 0;
}
#endif

#if 0
#include <iostream>
#define MAX_SIZE 13
using namespace std;

int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;
void dfs(int start, int depth){
    if(depth == 6){
        for(int i = 0; i < 6; i++){
            cout << combi[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start; i < k; i++){
        combi[depth] = lotto[i];
        dfs(i+1, depth+1);
    }
}
int main(){
    while(cin >> k && k){
        for(int i = 0; i < k; i++){
            cin >> lotto[i];
        }
        dfs(0,0);
        cout << '\n';
    }
    return 0;
}
#endif

#if 0
#include <stdio.h>
int a[49], b[49], k;
void print(int now, int z[49], int fill){
    int i;
    if(now == 6){
        for(i = 0; i < 6; i++){
            printf("%d ", z[i]);
        }
        printf("\n");
        return;
    }
    for(i = fill; i < k; i++){
        z[now] = a[i];
        print(now+1, z, i+1);
    }
    
}
int main(){
    int i;
    while(1){
        scanf("%d", &k);
        if(k == 0){
            break;
        }
        for(i = 0; i < k; i++){
            scanf("%d", &a[i]);
        }
        print(0, b, 0);
        printf("\n");
    }
}
#endif

#if 0
#include <stdio.h>
int a[6];
int k;
int result[6];
void f(int n, int pre){
    if(n == 0){
        for(int i = 0; i < 6; i++){
            printf("%d ", a[result[i]]);
        }
        printf("\n");
        return;
    }
    for(int i = pre + 1; i < k; i++){
        result[6-n] = i;
        f(n - 1, i);
    }
}
int main(){
    while(1){
        scanf("%d", &k);
        if(k == 0){
            break;
        }
        for(int i = 0; i < k; i++){
            scanf("%d", &a[i]);
        }
        f(6, -1);
        printf("\n");
    }
    return 0;
}
#endif
