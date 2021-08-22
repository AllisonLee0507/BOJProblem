#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#define MAX_SIZE 1005

int map[MAX_SIZE][MAX_SIZE];
int queue[MAX_SIZE*MAX_SIZE][2];

int front, back;
int N, M;
int zero_cnt;

int bfs(int row, int col);
void push(int x, int y);

int main(){
    int i, j;
    scanf("%d %d", &N, &M);
    for(i = 0; i <= N + 1; i++){
        for(j = 0; j <= M + 1; j++){
            if(i == 0 || j == 0 || i == N+1 || j == M+1){
                map[i][j] = -1;
            }
            else{
                scanf("%d", &map[i][j]);
                if(map[i][j] == 0){
                    zero_cnt++;
                }
                else if (map[i][j] == 1){
                    push(i, j);
                }
            }
        }
    }
    if(zero_cnt == 0){
        printf("0");
        return 0;
    }
    printf("%d\n", bfs(M,N));
    return 0;
}
void pop(){
    front++;
}
void push(int x, int y){
    queue[back][0] = x;
    queue[back][1] = y;
    back++;
}

int bfs(int row, int col){
    int i, j;
    int cur_x, cur_y;
    while(front != back){
        cur_x = queue[front][0];
        cur_y = queue[front][1];
        pop();
        
        if(map[cur_x - 1][cur_y] == 0){
            map[cur_x - 1][cur_y] = map[cur_x][cur_y] + 1;
            push(cur_x - 1, cur_y);
            zero_cnt--;
        }
        if(map[cur_x + 1][cur_y] == 0){
            map[cur_x + 1][cur_y] = map[cur_x][cur_y] + 1;
            push(cur_x + 1, cur_y);
            zero_cnt--;
        }
        if(map[cur_x][cur_y + 1] == 0){
            map[cur_x][cur_y + 1] = map[cur_x][cur_y] + 1;
            push(cur_x, cur_y + 1);
            zero_cnt--;
        }
        if(map[cur_x][cur_y - 1] == 0){
            map[cur_x][cur_y - 1] = map[cur_x][cur_y] + 1;
            push(cur_x, cur_y - 1);
            zero_cnt--;
        }
    }
    if(zero_cnt>0){
        return -1;
    }
    return map[cur_x][cur_y] - 1;
}
#endif

#if 0
#include <stdio.h>

int arr[1010][1010];
int point[1010*1010][2];
int point_next[1010*1010][2];
int point_count_next;
void check_box(int row, int col){
    if(arr[row][col] == 0){
        arr[row][col]= 1;
        point_next[point_count_next][0] = row;
        point_next[point_count_next][1] = col;
        
        point_count_next++;
    }
}
int main(){
    int row, col;
    int one_count = 0;
    int zero_count = 0;
    int day_count = 0;
    
    int point_count = 0;
    
    int point_row;
    int point_col;
    
    scanf("%d %d", &col, &row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
            
            if(arr[i][j] == 1){
                one_count++;
            }
            if(arr[i][j] == 0){
                zero_count++;
            }
        }
    }
    if(zero_count == 0){
        printf("0");
        return 0;
    }
    else if (one_count == 0){
        printf("-1");
        return 0;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 1){
                point[point_count][0] = i;
                point[point_count][1] = j;
                
                point_count++;
            }
        }
    }
    while(1){
        for(int i = 0; i < point_count; i++){
            point_row = point[i][0];
            point_col = point[i][1];
            if(point_row != 0){
                check_box(point_row - 1, point_col);
            }
            if(point_col != 0){
                check_box(point_row, point_col-1);
            }
            if(point_row != row - 1){
                check_box(point_row + 1, point_col);
            }
            if(point_col != col - 1){
                check_box(point_row, point_col+1);
            }
        }
        if(point_count_next == 0){
            break;
        }
        for(int i = 0; i < point_count_next; i++){
            point[i][0] = point_next[i][0];
            point[i][1] = point_next[i][1];
        }
        point_count = point_count_next;
        point_count_next = 0;
        
        day_count++;
    }
    zero_count = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j ++){
            if(arr[i][j] == 0){
                zero_count++;
            }
        }
    }
    if(zero_count != 0){
        printf("-1");
    }
    else{
        printf("%d", day_count);
    }
    return 0;
}
#endif
