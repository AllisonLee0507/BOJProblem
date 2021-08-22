#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int n;
    int arr[1010];
    int cnt;
    int min = 987654321;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(j<i)
            {
                cnt += (j+n-i)*arr[j];
            }
            else
            {
                cnt += (j-i)*arr[j];
            }
        }
        if(cnt < min)
        {
            min = cnt;
        }
    }
    printf("%d", min);
    return 0;
}
#endif
