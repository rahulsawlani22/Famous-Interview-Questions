//Find the first repeating character in the given string.

#include<string.h>
#include<iostream>
using namespace std;
#define max_char 256
int firstrepeat(char* str)
{
    int p = -1,i,j,k;
    int count[max_char]={0};
    int pos[max_char];
    for(i=0;i<strlen(str);i++)
    {
        k=(int)str[i];
        if(count[k]==0)
           {
             count[k]++;
             pos[k]=i;
           }
           else if(count[k]>=1)
           count[k]++;
    }
    for(j=0; j<max_char; j++)
    {
        if(count[j]>1)
        {
            if(p==-1)
            p=pos[j];
            else if(p>pos[j])
            p=pos[j];
        }
    }
    return p;
}
int main()
{
    char str[] ="geekforgeeks";
   
    cout<<str[firstrepeat(str)];
}