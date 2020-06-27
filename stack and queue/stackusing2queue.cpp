// implemnet stack using queue data structure.
// here we are using 2 queues to perform operations and making push operation costly (O(n)).
#include<iostream>
#include<queue>
using namespace std;
class Stack
{
    queue<int> q1,q2;
    int cur_size;
    public:

        void push(int x)
        {   cur_size++;
            q2.push(x);

            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> q=q1;
            q1=q2;
            q2=q;
        }
        void pop()
        {
            if(cur_size==0)
            cout<<"empty!";
            else
            {
                q1.pop();
            }
        }
        void size()
        {
            cout<<cur_size;
        }
        int top()
        {
            return q1.front();
        }
}
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