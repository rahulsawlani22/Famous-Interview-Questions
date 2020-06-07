//Find the nth Node from the end.

#include<iostream>
using namespace std;
struct Node{
    struct Node* next;
    int data;
};
void insertNode(struct Node** head, int x)
{
   struct Node *temp = new Node;
    temp->data=x;
    temp->next=*head;
   *head=temp;
    
}
void nthnode(struct Node** head,int n)
{
  struct Node *first = *head;
  struct Node *second = *head;
  if(head!=NULL)
   { for(int i=1;i<n;i++)
       first=first->next;
    
  while(first->next!=NULL)
  {
    second=second->next;
    first=first->next;
  }
  cout<<"the nth node from end is: "<<second->data;}
  else 
  return;


}
void printlist(Node* head)
{
    while(head!=NULL)
{cout<<head->data<<"->";
head=head->next;
}
cout<<endl;
}
int main()
{
    struct Node* head = NULL;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);
    printlist(head);
    nthnode(&head,1);
    
}