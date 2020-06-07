//Remove the loop from the linklist if it exists.

//The solution is the continuation from floyd's algorithm for finding loop.
#include<iostream>
#include<unordered_set>
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
bool detectloophash(struct Node* head)
{
    unordered_set<Node*> s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end())
        return true;
        s.insert(head);
        head=head->next;
    }
      return false;

}
void detectloopandremove(struct Node* head)
{
    if( head == NULL || head->next==NULL)
    return;
    struct Node* slow=head;
    struct Node* fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
void printList(Node* head) 
{ 
    while (head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
    cout << endl; 
} 
  

int main()
{
    struct Node* head = NULL;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);
    head->next->next->next->next->next = head->next;
    detectloopandremove(head);
    printList(head);
   
    
}