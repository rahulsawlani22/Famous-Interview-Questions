// Find middle of the link list.

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
void middlenode(struct Node** head)
{
  struct Node *slow = *head;
  struct Node *fast = *head;
  while(fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  cout<<"the middle node is: "<<slow->data;


}
void printlist(Node* head)
{
    while(head!=NULL)
{cout<<head->data<<"->";
head=head->next;
}

}
int main()
{
    struct Node* head = NULL;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);

    middlenode(&head);
    
}