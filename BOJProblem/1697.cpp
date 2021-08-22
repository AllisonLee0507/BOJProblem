#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <queue>
#define MAX 1000000

using namespace std;
int N, K;
bool Visit[MAX];
int dx[] = {-1, 1};

void Input(){
    cin >> N >> K;
}
void BFS(int a){
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, 0));
    Visit[a] = true;
    
    while(Q.empty() == 0){
        int x = Q.front().first;
        int t = Q.front().second;
        Q.pop();
        
        if(x == K){
            cout << t << endl;
            return;
        }
        for(int i = 0; i < 2; i++){
            int nx = x + dx[i];
            if(nx >= 0 && nx < MAX){
                if(Visit[nx] == false){
                    Q.push(make_pair(nx, t+1));
                    Visit[nx] = true;
                }
            }
        }
        if(x*2<MAX){
            if(Visit[x*2] == false){
                Q.push(make_pair(x*2, t+1));
                Visit[x*2] = true;
            }
        }
    }
}
void Solution(){
    BFS(N);
}
void Solve(){
    Input();
    Solution();
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int x1, result;

int cal(int val){
    int cc = 1;
    int cc1 = 0;
    int cc2 = 0;
    
    if(val == x1){
        return cc - 1;
    }
    if(val / 2 >= x1){
        if(val % 2 == 0){
            cc += cal(val / 2);
        }
        else{
            if(x1 != 0 || val != 1){
                cc1 = cal(val + 1);
                cc2 = cal(val - 1);
            }
        }
    }
    else{
        if(val % 2 == 0){
            cc1 = val - x1 - 1;
            cc2 = x1 - val /2;
        }
        else{
            cc1 = val - x1 - 1;
            cc2 = x1 - (val + 1)/2 + 1;
        }
    }
    if(cc1 < cc2){
        cc += cc1;
    }
    else{
        cc += cc2;
    }
    return cc;
}

int main(){
    scanf("%d %d", &x1, &result);
    if(result < x1){
        printf("%d", x1 - result);
    }
    else{
        printf("%d", cal(result));
    }
    return 0;
}

#endif

#if 0
#include <stdio.h>
#define qmax 50000

typedef struct st{
    int p, cnt;
}NODE;

NODE que[qmax];
int w, r;
int s, d;
char check[100000 + 1000];

int main(void){
    scanf("%d%d", &s, &d);
    que[w].p = s;
    que[w++].cnt = 0;
    check[s] = 1;
    w %= qmax;
    
    while(w != r){
        NODE cur = que[r++];
        if(cur.p == d){
            printf("%d", cur.cnt);
            break;
        }
        int ns[3] = {cur.p + 1, cur.p - 1, cur.p *2};
        r %= qmax;
        for(int i = 0; i < 3; i++){
            if(ns[i] < 0 || ns[i] > 100000){
                continue;
            }
            if(check[ns[i]]){
                continue;
            }
            check[ns[i]] = 1;
            que[w].p = ns[i];
            que[w++].cnt = cur.cnt +1;
            w %= qmax;

        }
//        for (int i = 0; i < 3; i++)
//        {
//            if (ns[i] < 0 || ns[i] > 100000) continue;
//            if (check[ns[i]]) continue;
//
//            check[ns[i]] = 1;
//            que[w].p = ns[i];
//            que[w++].cnt = cur.cnt + 1;
//            w %= qmax;
//        }
    }
    return 0;
}
#endif

#if 0
#include <stdio.h>
#define qmax 50000

typedef struct st
{
    int p, cnt;
}NODE;

NODE que[qmax];

int w, r;
int s, d;

char check[100000 + 1000];

int main(void)
{
    scanf("%d%d", &s, &d);

    que[w].p = s;
    que[w++].cnt = 0;
    check[s] = 1;
    w %= qmax;

    while (w != r)
    {
        NODE cur = que[r++];
        if (cur.p == d)
        {
            printf("%d", cur.cnt);
            break;
        }
        int ns[3] = { cur.p + 1, cur.p - 1, cur.p * 2 };
        r %= qmax;
        for (int i = 0; i < 3; i++)
        {
            if (ns[i] < 0 || ns[i] > 100000) continue;
            if (check[ns[i]]) continue;

            check[ns[i]] = 1;
            que[w].p = ns[i];
            que[w++].cnt = cur.cnt + 1;
            w %= qmax;
        }
    }

    return 0;
}
#endif
