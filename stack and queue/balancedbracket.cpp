// program to check balnced brackets using stack

#include<iostream>
#include<stack>
#include<string>

using namespace std;
// "(()"
bool checkbalance(string str)
{
    int i;
    stack<char> bracs;
    if(str.size()==1||str.size()==0)
        return false;
    for (i=0;i<str.size();i++)
        {
            if(str[i]==']'||str[i]=='}'||str[i]==')')
            {
                if(bracs.top()!=str[i])
                    return false;
                else bracs.pop();
            }
            bracs.push(str[i]);
        }
    if(bracs.empty())
        return true;
    else return false;    
}
int main()
{
    string s;
    cout<<"Enter the String of brackets";
    cin>>s;
    if(checkbalance(s))
    cout<<"Yes";
    else cout<<"No";
    return 0;

}

