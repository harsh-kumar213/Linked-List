#include<iostream>
#include<map>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   Node(int d)
   {
      this->data=d;
      this->next=NULL;
   }
};

void insertAtTail(Node* &tail,int d)
{
    Node *temp = new Node(d);
    tail->next=temp;
    tail = temp;
}


void print(Node* &head)
{
    Node * temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

bool detectLoop(Node*head)
{
    if(head==NULL)
    return false;

    Node*slow = head;
    Node*fast= head;

    while(slow!=NULL && fast!=NULL)
    {
       slow = slow->next;

       fast = fast->next;
       if(fast!=NULL)
       {
          fast= fast->next;
       }
       if(slow == fast)
       {
          cout<<"cycle is present at "<<slow->data<<endl;
          return true;
       }
    }
    return false;
}

Node * getStartingNode(Node* head)
{
    if(head==NULL)
    return NULL;

    Node*slow = head;
    Node*fast= head;

     while(slow!=NULL && fast!=NULL)
    {
       slow = slow->next;

       fast = fast->next;
       if(fast!=NULL)
       {
          fast= fast->next;
       }
       if(slow == fast)
       {
           break;
       }
    }
  
    slow = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void removeLoop(Node* head)
{
    if(head==NULL)
      return ;

     Node * startOfLoop = getStartingNode(head);
     Node * temp = startOfLoop;
     while(temp->next!=startOfLoop)
     {
        temp = temp->next;
     } 
     temp->next = NULL;
}

int main()
{
    Node * linkedList = new Node(2);
    Node*head = linkedList;
    Node*tail = linkedList;
     
    insertAtTail(tail,4);
    insertAtTail(tail,6);
    insertAtTail(tail,8);
    insertAtTail(tail,10);
    insertAtTail(tail,12);

    
    tail->next = head->next;
      
     Node  * temp = getStartingNode(head);
     cout<<"loop starts at "<<temp->data<<endl;
     
     removeLoop(head);
     print(head);
    return 0;
}