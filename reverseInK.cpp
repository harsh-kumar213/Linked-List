#include<iostream>
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

void insertAtTail(Node*&tail,int d)
{
    Node*temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node*&head)
{
    Node*temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<endl; 
}

Node * kreverse(Node*&head,int k)
{
   
    // base case
    if(head==NULL)
    {
        return NULL;
    }

    // step1 : reverse first k nodes
    Node * prev = NULL;
    Node* curr = head;
    Node*next = NULL;
    int count=0;
    while(curr!=prev && count<k){
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr= next;
         count++;
    }

    // step2 : recursive call
    head->next = kreverse(next,k);

    // step3: return prev cause new head it that
    return prev;
}

int main()
{
    Node * LinkedList = new Node(3);
    Node*head = LinkedList;
    Node*tail = LinkedList;

    insertAtTail(tail,5);
    insertAtTail(tail,7);
    insertAtTail(tail,9);
    insertAtTail(tail,11);
    insertAtTail(tail,13);
    print(head);
    head = kreverse(head,2);
    print(head);

    return 0;
}