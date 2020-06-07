/* Find the nth number from read and call Sequence.
A read and call sequence is shown below.
1
11
21
1211 
111221
*/
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
string ret(int n)
{
    if (n==1)
    return("1");
    if (n==2)
    return("11");
    string str= "11";
    for(int i=3;i<=n;i++)
    {
        str+='$';
        string tmp = "";
        int cnt=1;
        int len=str.length();
        for(int j=1;j<len;j++)
        {
            if(str[j]!=str[j-1])
            {
                tmp+=cnt+'0';
                tmp+=str[j-1];
                cnt=1;
            }
            else cnt++;     
        }
        str=tmp;
    }
   return str;
}
int main()
{
      cout<<ret(4);
}