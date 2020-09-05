
#include<iostream>
#include<queue>
using namespace std;

void printmedian(double arr[], int size)
{
  priority_queue<double> l;
  priority_queue<double , vector<double>, greater<double>> r;
  double m = arr[0];
  cout<<m<<" ";
  int i,j;
  l.push(arr[0]);
  for(i=1;i<size;i++)
  {
    double x = arr[i];
    if(l.size()>r.size())
    {
      if(x<m){
        r.push(l.top());
        l.pop();
        l.push(x);
      }
      else r.push(x);
      m = (l.top()+r.top())/2.0;
    }
    else if(l.size()<r.size())
    {
        if(x>m){
        l.push(r.top());
        r.pop();
        r.push(x);
      }
      else l.push(x);
      m = (l.top()+r.top())/2.0;
    }
    else
    {
      if(x>m)
      {
        r.push(x);
      m=(double)r.top();
      }
      else{
        l.push(x);
        m=(double)l.top();
      }
    }
  cout<<m<<" ";
}}
int main()
  {
    double arr[]={10,20,30,40,50,60};
    int size = sizeof(arr)/(sizeof(arr[0]));
    printmedian(arr,size);
    return 0;
  }

