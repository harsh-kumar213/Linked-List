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
/*
void sort(Node * head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node * temp = head;
    while(temp!=NULL)
    {
        if(temp->data==0)
          zeroCount++;
        else if(temp->data==1)
          oneCount++;
        else if(temp->data==2)
          twoCount++;
       
        temp= temp->next;
    }
    temp = head;

    while(temp!=NULL)
    {
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0)
        {
            temp->data=1;
            oneCount--;
        }
        else
        {
            temp->data=2;
            twoCount--;
        }
         temp= temp->next;
    }
}
*/
// approach 2

void insert(Node *& tail,Node*curr)
{
    tail->next = curr;
    tail =curr;
}

Node* sort(Node*&head)
{
    Node * zeroHead = new Node(-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node * twoTail = twoHead;

    Node * curr = head;
  // add elements in three linked lists
    while(curr!=NULL)
    {
        int value = curr->data;
        if(value==0)
        insert(zeroTail,curr);
        else if(value==1)
        insert(oneTail,curr);
        else if(value==2)
        insert(twoTail,curr);

        curr = curr->next;
        
    }

    // merge three linked lists
    if(oneHead!=NULL)
      zeroTail->next = oneHead->next;
    else
      zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // set Head 
      head = zeroHead->next;
    // delete unNeeded nodes
    delete oneHead;
    delete zeroHead;
    delete twoHead;

    return head;

}

int main()
{
    Node* linkedList = new Node(0);
    Node* head = linkedList;
    Node*tail = linkedList;
    
    insertAtTail(tail,2);
    insertAtTail(tail,0);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
   print(head);
   head =  sort(head);
    print(head);
}