#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
char s[1000001];
char boom[101];
vector<char> v;
int sl, bl;

bool reveal(){
    int ssize = (int)v.size()-1;
    for(int i = bl-1; i >=0; i--){
        if(boom[i] != v[ssize - bl + 1 +i]){
            return false;
        }
    }
    return true;
}
void p(){
    for(int i = 0; i < bl; i++){
        if(!v.empty()){
            v.pop_back();
        }
    }
}
int main(){
    scanf("%s %s", s, boom);
    sl = (int)strlen(s);
    bl = (int)strlen(boom);
    for(int i = 0; i <sl; i++){
        v.push_back(s[i]);
        if(reveal()){
            p();
        }
    }
    int ssize = (int)v.size();
    for(int i = 0; i<ssize; i++){
        printf("%c", v[i]);
    }
}
#endif

//
#if 0
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
char s[1000001];
char boom[101];
vector<char> v;
int sl, bl;

bool reveal() {
   int ssize = v.size() - 1;
   for (int i = bl - 1; i >= 0; i--)
   {
      if (boom[i] != v[ssize - bl + 1 + i])
      {
         return false;
      }

   }
   return true;
}

void p()
{
   for (int i = 0; i < bl; i++)
   {
      if (!v.empty())
      {
         v.pop_back();
      }
   }
}
int main() {
   scanf("%s %s", s, boom);
   sl = strlen(s);
   bl = strlen(boom);
   for (int i = 0; i < sl; i++)
   {
      v.push_back(s[i]);
      if (reveal())
      {
         p();
      }
   }
   int ssize = v.size();

   for (int i = 0; i < ssize; i++)
   {
      printf("%c", v[i]);
   }
   return 0;
}
#endif
