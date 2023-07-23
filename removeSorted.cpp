#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data= d;
        this->next = NULL;
    }

};

void insertAtTail(Node*&tail,int d)
{
     Node * temp = new Node(d);
     tail->next = temp;
     tail = temp;
}

void removeDuplicate(Node*&head)
{
    Node * temp = head;
    while(temp!=NULL)
    {
      
       if( (temp->next!=NULL) && temp->data == temp->next->data)
       {
           Node*next_next = temp->next->next;
           Node * temp2 = temp->next;
          
           delete(temp2);
           temp->next = next_next;
          
       }
       else{

           temp = temp->next;
       }
          
    }
}

void print (Node*head)
{
    Node*temp = head;
    cout<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* linkedList = new Node(1);
    Node*head = linkedList;
    Node*tail = linkedList;

    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    print(head);
    removeDuplicate(head);
    print(head);
    
    return 0;
}