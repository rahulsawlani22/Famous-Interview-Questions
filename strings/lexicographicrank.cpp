// find the lexicograpic rank of the input string.

#include<iostream>
#include<string.h>
using namespace std;
int fact(int n)
{
    if(n<=1)
    return 1;
    else return n*fact(n-1);
}
int lexrank(char *str)
{
    int n=str.length();
    int mul = fact(n);
    int i,j;
    int rank=1;
    int count[256] = {0};
    for(i=0;i<256;i++)
        count[str[i]]++;
    for(i=0;i<256;i++)
        count[i] = count[i] + count[i-1];
    for(i=0;i<n;i++)
    {
        mul=mul/(n-i);
        rank=rank + (count[str[i]-1]*mul);
        for(j=count[str[i]];j<256;j++)
            count[j]--;
    }
    return rank;

}
int main()
{
    char str[]="STRING";
    int r = lexrank(str);
    cout<<r;

}