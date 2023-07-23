#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * random;

    Node(int d)
    {
        this->data =d;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node *&tail,int d)
{
    Node * temp = new Node(d);
    tail->next = temp;
    tail =  temp;
}

void pointRandom(Node * head,Node * curr,int d2)
{
    Node * temp = head;
    int d = temp->data;
    while(temp!=NULL && d != d2)
    {
         temp = temp->next;
         d = temp->data;
    }

    curr->random = temp;

}

int main()
{
    Node * linkedList = new Node(1);
    Node * head= linkedList;
    Node * tail = linkedList;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
  
    Node * temp = head;
    int d = 0;
    while(temp!=NULL)
    {
        if(temp->data==1)
          d = 3;
        if(temp->data==2)
          d = 1;
        if(temp->data==3)
          d = 5;
        if(temp->data==4)
          d = 3;
        if(temp->data==5)
          d = 2;  
        pointRandom(head,temp,d);
    }

    cout<<head->random->data<<endl;

    return 0;
}