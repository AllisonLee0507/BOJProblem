#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <string.h>
int main(){
    char S[1000];
    int len, i;
    gets(S);
    while (strcmp(S, "END")){
        len = (int)strlen(S);
        for(i = len -1; i >= 0; i--){
            printf("%c", S[i]);
        }
        printf("\n");
        gets(S);
    }
    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        string line;
        getline(cin, line);
        if(line == "END"){
            break;
        }
        reverse(line.begin(), line.end());
        cout << line << endl;
    }
}
#endif
