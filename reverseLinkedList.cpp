#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        this->data = d;
        this->next=NULL;
    }
};

void insertAtTail(Node* &tail,int d)
{
    Node * temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// approach one - iterative solution

/*void reverse(Node*&head,Node*&tail)
{
    Node * prev =NULL;
    Node* curr = head;
    tail = head;
    while(curr!=NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        head =prev;

    }
}*/

void reverse(Node*&head,Node*curr,Node* prev)
{
    
    if(curr==NULL){
     head = prev;
    return;
    }
    
    
    Node* forward = curr->next;
    reverse(head,forward,curr);
    curr->next= prev;
  



}

int main()
{
    Node *n1 = new Node(10);
    Node * head = n1;
    Node* tail = n1;

    insertAtTail(tail,12);
    insertAtTail(tail,14);
    print(head);

    cout<<"head: "<<head->data<<endl<<endl;
    cout<<endl<<"tail: "<<tail->data<<endl<<endl; 

    Node* curr = head;
    Node * prev = NULL;

    reverse(head,curr,prev);
    print(head);

    cout<<endl<<"head: "<<head->data<<endl<<endl;
    cout<<endl<<"tail: "<<tail->data<<endl<<endl;    
    return 0;
}
