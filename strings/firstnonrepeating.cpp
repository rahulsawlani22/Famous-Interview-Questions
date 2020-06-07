// Find the the first non-repeating character in the given string. 
#include<string.h>
#include<iostream>
using namespace std;
#define max_char 256
int firstrepeat(char* str)
{
    int p = -1,i,j;
    
   pair<int,int> count[max_char];
   for(i=0; i < strlen(str); i++)
   {
     count[str[i]].first++;
     count[str[i]].second=i;
   }
    for(j=0; j<max_char; j++)
    {
        if(count[j].first==1)
        {
            if(p==-1)
            p=count[j].second;
            else if(p>count[j].second)
            p=count[j].second;
        }
    }
    return p;
}
int main()
{
    char str[] ="geekforgeeks";

    cout<<str[firstrepeat(str)];
}