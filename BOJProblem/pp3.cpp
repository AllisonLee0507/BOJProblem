#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <vector>
#include <cstdbool>
#include <utility>

#define X first
#define Y second

using namespace std;

int N;
char direction[50];

struct Cow
{
   char direction;
   int x, y;
   int grass = 1;
   bool stop = false;
   bool inf = false;
};
typedef struct Cow Cow;

Cow bessie[50];

vector<pair<int, int>> C;
bool loop = true;

int main()
{
   scanf("%d", &N);
   for (int i = 0; i < N; i++)
   {
      scanf(" %c %d %d", &bessie[i].direction, &bessie[i].x, &bessie[i].y);
   }
    for (;loop;)
   {
      for (int i = 0; i < N; i++)
      {
         if (bessie[i].stop == false && bessie[i].direction == 'E')
         {
            bessie[i].x++;
            bessie[i].grass++;
            C.push_back(make_pair(bessie[i].x, bessie[i].y));
         }
         if (bessie[i].stop == false && bessie[i].direction == 'N')
         {
            bessie[i].y++;
            bessie[i].grass++;
            C.push_back(make_pair(bessie[i].x, bessie[i].y));
         }
      }

      for (int i = 0; i < N; i++)
      {
         for (int n = 0; n < C.size(); n++)
         {
            if (bessie[i].direction == 'E' && C[n].first == (bessie[i].x + 1) && C[n].second == bessie[i].y)
               bessie[i].stop = true;
   
            if (bessie[i].direction == 'N' && C[n].first == bessie[i].x && C[n].second == (bessie[i].y + 1))
               bessie[i].stop = true;
         }

         if(bessie[i].stop == false )
         {
            bessie[i].inf = true;
            for (int j = 0; j < N; j++)
            {
               if(i != j && bessie[j].inf == false)
               {
                  if (bessie[i].direction == 'E' && bessie[i].x < bessie[j].x )
                     bessie[i].inf = false;
                  
                  if (bessie[i].direction == 'N' && bessie[i].y < bessie[j].y)
                     bessie[i].inf = false;
               }
            }
         }
      }

      loop = false;
      for (int i = 0; i < N; i++)
      {
         if (bessie[i].inf == true)
            continue;
         else if (bessie[i].stop == false)
         {
            loop = true;
            break;
         }
      }
   }

   for (int i = 0; i < N; i++)
   {
      if (bessie[i].inf)
         printf("Infinity\n");
      else
         printf("%d\n", bessie[i].grass);
   }
   return 0;
}

#endif
