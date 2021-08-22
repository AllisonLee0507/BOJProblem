#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef set<int> inSet;

class gpNode{
public:
    gpNode():flag(false){}
    bool flag;
};
class Graph{
private:
    int size;
    gpNode *node;
    inSet *adj;
public:
    Graph():size(5){
        node = new gpNode[5];
        adj = new inSet[5];
    }
    Graph(int n):size(n){
        node = new gpNode[n];
        adj = new inSet[n];
    }
    ~Graph(){
        delete[] node;
        delete[] adj;
    }
    int BFS(int start){
        int result = 0;
        queue<int> next;
        int qsize, current;
        next.push(start);
        while(!next.empty()){
            qsize = next.size();
            for(int i = 0; i < qsize; i++){
                current = next.front();
                next.pop();
                if(node[current].flag){
                    continue;
                }
                node[current].flag = true;
                result++;
                inSet & curSet = adj[current];
                for(inSet::iterator iter = curSet.begin(); iter!=curSet.end(); iter++)
                {
                    next.push(*iter);
                }
            }
        }
        return result-1;
    }
    void addEdge(int u, int v){
        adj[u].insert(v);
        adj[v].insert(u);
    }
};
int main(){
    int N, M;
    int p, q;
    
    cin >> N >> M;
    Graph gp(N);
    
    for(int i = 0; i < M; i++){
        cin >> p >> q;
        gp.addEdge(p-1, q-1);
    }
    cout << gp.BFS(0) << endl;
    
    return 0 ;
    
}
#endif 

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int c1;
    int c2;
}pairOfComputers;

int main()
{
    int n;
    int cpt[100] = {};
    int cnt = 0;
    int pair;
    cpt[0] = 1;
    scanf("%d", &n);
    scanf("%d", &pair);
    
    pairOfComputers* p = (pairOfComputers*)malloc(sizeof(pairOfComputers) * pair);
    //pariOfCompter p[6];
    for(int i = 0; i < pair; i ++){
        scanf("%d %d", &(p[i].c1), &(p[i].c2));
    }
    for(int j = 0; j < 100; j ++)
    {
        for(int i = 0; i < pair; i++){
            if(cpt[p[i].c1-1]==1 || cpt[p[i].c2-1] == 1)
            {
                cpt[p[i].c1-1] = 1;
                cpt[p[i].c2-1] = 1;
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(cpt[i] == 1){
            cnt++;
        }
    }
    printf("%d", cnt);
    free (p);
}
#endif
