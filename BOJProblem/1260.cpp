#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
typedef struct p{
    int f;
    int t;
}P;

int V, E, S, i, cnt[1001], c, check[1001], Q[50001], F, T;
P EL[20001];
//void q(int l, int r){
//    if(l < r){
//        int i = l - 1, j = r + 1, pi = EL[(i+j)/2].f, qi = EL[(i+j)/2].t;
//        P t;
//        while (i < j){
//            while(EL[++i].f < pi || (EL[i].f == pi && EL[i].t<qi));
//            while(EL[--j].f > pi || (EL[j].f == pi && EL[j].t<qi));
//            if( i >= j){
//                break;
//            }
//            t = EL[j];
//            EL[i] = EL[j];
//            EL[j] = t;
//        }
//        q(l, i-1);
//        q(j+1, r);
//    }
//}

void q(int l, int r)
{
   if (l < r)
   {
      int i = l - 1, j = r + 1, pi = EL[(i + j) / 2].f, qi = EL[(i + j) / 2].t;
      P t;
      while (i < j)
      {
         while (EL[++i].f < pi || (EL[i].f == pi && EL[i].t < qi));
         while (EL[--j].f > pi || (EL[j].f == pi && EL[j].t > qi));
         if (i >= j)break;
         t = EL[i];
         EL[i] = EL[j];
         EL[j] = t;
      }
      q(l, i - 1);
      q(j + 1, r);
   }
}


void DFS(int s){
    printf("%d ", s);
    check[s] = 1;
    for(int i = cnt[s - 1]; i < cnt[s]; i++){
        if(check[EL[i].t]){
            continue;
        }
        DFS(EL[i].t);
    }
}

void BFS(int s){
    Q[T++] = s;
    check[s] = 1;
    while(F != T){
        int pop = Q[F++];
        printf("%d ", pop);
        for(int i = cnt[pop-1]; i < cnt[pop]; i++){
            int v = EL[i].t;
            if(check[v]){
                continue;
            }
            Q[T++] = v;
            check[v] = 1;
        }
    }
}

int main(){
    scanf("%d %d %d", &V, &E, &S);
    for( i = 0; i < 2 *E; i += 2){
        scanf("%d %d", &EL[i].f, &EL[i].t);
        EL[i+1].f = EL[i].t, EL[i+1].t = EL[i].f;
    }
    q(0, 2*E-1);
    for(int i = 1; i <= V; i++){
        while(EL[++c].f == EL[c-1].f);
        cnt[i] = c;
    }
    DFS(S);
    printf("\n");
    for(int i = 1; i <= V; i++){
        check[i] = 0;
    }
    BFS(S);
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>

int q[1000], qf, qb, qs, n, m, v;
char p[1001][1001], vt[1001];
void dfs(int v){
    int i;
    printf("%d ", v);
    vt[v] = 1;
    for(i = 1; i <= n; i++){
        if(p[v][i] == 1 && vt[i] == 0){
            dfs(i);
        }
    }
}
void bfs(int v){
    int i, j;
    memset(vt, 0, 1001);
    q[qb++] = v;
    qs++;
    vt[v] = 1;
    
    while(qs){
        i = q[qf++];
        qs-- ;
        printf("%d ", i);
        for(j = 1; j <= n; j++){
            if(!vt[j] && p[i][j]){
                q[qb++] = j;
                qs++;
                vt[j] = 1; 
            }
        }
    }
}

int main(){
    int i, a, b;
    scanf("%d %d %d", &n, &m, &v);
    for(i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        p[a][b] = (p[b][a] = 1);
    }
    dfs(v);
    printf("\n");
    bfs(v);
    printf("\n");
    
}
#endif
