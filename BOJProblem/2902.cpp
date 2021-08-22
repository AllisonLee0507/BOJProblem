#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    char a[101];
    int i;

    scanf("%s", a);
    printf("%c",a[0]);
    for(i = 0; i<100; i++){
        if(a[i] == '-'){
            printf("%c",a[i+1]);
        }
    }
    return 0;
}

#endif 

#if 0
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    int i;

    cin >> a;
    printf("%c",a[0]);
    for(i = 0; i<100; i++){
        if(a[i] == '-'){
            printf("%c",a[i+1]);
        }
    }
    return 0;
}

#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    int i;

    cin >> a;

    for(i = 0; i<a.length(); i++){
        //if(a[i] >= 'A' && a[i] <= 'Z'){
        if(a[i] >= 65 && a[i] <= 90){
            printf("%c",a[i]);
        }
    }
    return 0;
}

#endif

