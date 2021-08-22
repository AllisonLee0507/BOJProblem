#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    char s[m][n];
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%c", &s[i][j]);
        }
    }
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}
#endif

#if 0
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    char s[m][n];
    for(int i = 0; i<m; i++)
    {
        scanf("%s", s[i]);
    }
    for(int i = 0; i<m; i++)
    {
        for(int q = 0; q<k; q++)
        {
            for(int j = 0; j<n; j++)
            {
                for(int p = 0; p<k; p++)
                {
                    printf("%c", s[i][j]);
                }
            }
            printf("\n");
        }
    }
}
#endif
