//Find wether a linked list contains a loop or not.

//The solution contains two effective ways of solving. One is hashing and other is the Floyd's algorithm.
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
bool detectloopfloyd(struct Node*head)
{
    struct Node* slow=head;
    struct Node* fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
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
    if(detectloopfloyd(head))
    cout<<"Loop found!";
    else
    {
        cout<<"loop not found";
    }
    
    
}
