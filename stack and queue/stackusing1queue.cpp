#include<iostream>
#include<queue>
using namespace std;
class Stack
{
    queue<int> q;
    int cur_size;
    public:

        void push(int x)
        {   cur_size++;
            int s=q.size();
            q.push(x);

            for(int i=0;i<s;i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
        void pop()
        {
            if(cur_size==0)
            cout<<"empty!";
            else
            {
                q.pop();
            }
        }
        void size()
        {
            cout<<cur_size;
        }
        int top()
        {
            return q.front();
        }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top();
    s.pop();
    cout<<s.top();
    s.pop();
    cout<<s.top();
    

}