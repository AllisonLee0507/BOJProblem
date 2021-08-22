#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>

using namespace std;

int main(void)
{
   string s2,s3;

   cin.tie(0);
   ios::sync_with_stdio(false);

   cin >> s2 >> s3;

   for(int i=0;i<s2.length();i++)
   {
      string t = s2;
      if(t[i]=='0')
      {
         t[i]='1';
      }
      else
      {
         t[i]='0';
      }
      int num = 0;
      int mul = 1;
      for(int j=t.length()-1;j>=0;j--)
      {
         num += (mul*(t[j]-'0'));
         mul*=2;
      }

      string c;
      int temp = num;
      while(temp>0)
      {
         c = (char)(temp%3 + '0') + c;
         temp/=3;
      }

      int count = 0;
      if(c.length()!=s3.length())
      {
         continue;
      }

      for(int j=0;j<c.length();j++)
      {
         if(c[j]!=s3[j])
         {
            count++;
         }
      }

      if(count==1)
      {
         cout << num << '\n';
         break;
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
    string s2, s3;
    string t;
    int i;
    cin >> s2 >> s3;

    for (i = 0; i<s2.length(); i++){
        t = s2;
        if (t[i]=='0'){
            t[i] = '1';
        }
        else{
            t[i] = '0';
        }
        int num = 0;
        int mul = 1;
        for(int j = ((int)t.length())-1; j>=0; j--){
            num += (mul*(t[j]-'0'));
            mul*=2;
         }
        string c;
        int temp = num;
        while(temp > 0){
            c = (char)(temp%3 + '0') + c;
            temp /=3;
        }
        int count = 0;
        if(c.length()!=s3.length()){
            continue;
        }
        for(int j = 0; j<c.length(); j++){
            if (c[j]!=s3[j]){
                count++;
    
            }
        }

        if(count == 1){
            cout << num << endl;
            break;
        }
    }
    return 0;
}
#endif
