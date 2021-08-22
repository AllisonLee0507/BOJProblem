#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n;
    int i, j;
    
    cin >> n;

    string str, temp;
    cin >> str;
    int size = str.length();
    
    for(i = 1; i < n; i++)
    {
        cin >> temp;
        
        for(j = 0; j < size; j++)
        {
            if(str[j] == '?')
            {
                continue;
            }
            if(str[j] != temp[j])
            {
                str[j] = '?';
            }
        }
        
    }
    cout << str;
    
    return 0;

}

#endif
