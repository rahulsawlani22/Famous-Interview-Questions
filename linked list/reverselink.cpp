// Reverse the link list.

//The solution here is recursive and iterative solution is also possible.
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
void reverse( struct Node* prev,struct Node* cur,struct Node **head)
{
  
    if(cur->next==NULL)
   { *head=cur;
    cur->next=prev;
    return;}
    Node *next = cur->next;
    cur->next = prev;
    reverse(cur,next,head);
  
}
void reverselink(struct Node** head)
{
    reverse(NULL,*head,head);
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
    reverselink(&head);
    printlist(head);
    
}