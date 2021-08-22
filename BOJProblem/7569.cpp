#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

#define MAX 104
#define Q 400004

typedef struct tagpos{
    int z;
    int y;
    int x;
}POS;

int di[6][3] = { {0,0,1},{0,1,0},{0,0,-1},{0,-1,0},{1,0,0},{-1,0,0} };

int box[MAX][MAX][MAX];
int badtomato;

POS q[Q];
int front, rear;
void enq(POS i){
    q[rear] = i;
    rear = ++rear % Q;
    return;
}
POS deq(){
    POS temp = q[front];
    front = ++front % Q;
    return temp;
}
int main(){
    int M, N, H;
    int z, y, x;
    POS deqtemp;
    
    scanf("%d %d %d", &M, &N, &H);
    for(z = 1; z <= H; z++){
        for(y = 1; y <= N; y++){
            for(x = 1; x <= M; x++){
                int c;
                POS temp;
                scanf("%d", &c);
                if(c == 0){
                    badtomato++;
                }
                if(c == 1){
                    temp.z = z;
                    temp.y = y;
                    temp.x = x;
                    enq(temp);
                }
                box[z][y][x] = c;
            }
        }
    }
    while(front != rear){
        int newy, newx, newz;
        POS newtemp;
        deqtemp = deq();
        
        for(int i = 0; i < 6; i++){
            newz = newtemp.z = deqtemp.z + di[i][0];
            newy = newtemp.y = deqtemp.y + di[i][1];
            newx = newtemp.x = deqtemp.x + di[i][2];
            if(box[newtemp.z][newtemp.y][newtemp.x] == 0){
                if(1 > newy || newy > N || 1 > newx || newx > M ||  1 > newz || newz > H){
                    continue;
                }
                box[newz][newy][newx] = box[deqtemp.z][deqtemp.y][deqtemp.x] + 1;
                enq(newtemp);
                badtomato--;
            }
        }
    }
    if(badtomato != 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", box[deqtemp.z][deqtemp.y][deqtemp.x] - 1);
    }
    return 0;
}

#endif
