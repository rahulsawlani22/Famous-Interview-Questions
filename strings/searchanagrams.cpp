//seach anagrams in the string.

#include<iostream>
#include<string.h>
using namespace std;
bool check(int a[],int b[])
{
    for(int i=0;i<256;i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}
void searchana(char* s,char* a)
{
    int i,j,k,flag=0;
    int m=strlen(a);
    int n=strlen(s);
    int c2[256]={0};
     int c1[256]={0};
    for(i=0; i<strlen(a); i++)
    {
        c2[a[i]]++;
        c1[s[i]]++;
    }
    for(i=m;i<n;i++)
   {
       if(check(c1,c2))
       cout<<" yes at "<<i-m;
       c1[s[i]]++;
       c1[s[i-m]]--;
   }
    if(check(c1,c2))
    cout<<" and at "<<n-m;  
}
int main()
{
    char str[]= "geeksforgeeks";
    char ana[]="for";

    searchana(str,ana);
    
}