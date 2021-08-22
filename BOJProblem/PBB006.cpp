#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <queue>
struct VERTEX{int a, b;};
int h, w, Sa, Sb, Ga, Gb, visited[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char M[101][101];
bool safe(int a, int b){
    return (0<=a && a<h) && (0<=b && b<w);
}
void input(void){
    scanf("%d%d", &h, &w);
    for (int i = 0; i<h; i++){
        scanf("%s", M[i]);
        for(int j = 0; j<w; j++){
            if(M[i][j] == 'S'){
                Sa = i;
                Sb = j;
            }
            else if(M[i][j] == 'G'){
                Ga = i;
                Gb = j;
                M[i][j] = '.';
            }
        }
    }
    return;
}
int solve(void){
    std::queue<VERTEX
}
int main(){
    input();
    printf("%d", solve());
    return 0;
    
}

#endif
