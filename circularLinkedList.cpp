#include<iostream>
using namespace std;

class Node{
   
   public:
   int data;
   Node* next;

   // constructor
   Node(int d)
   {
    this->data = d;
    this->next = NULL;
   }

   ~Node()
   {
    
      if(this->next!=NULL)
      {
        delete next;
        next = NULL;
      }
   }

};

void insertNode(Node * &tail,int element,int d)
{
    //empty list
    if(tail==NULL)
    {
        Node * newNode =new Node(d);
        newNode->next=newNode;
        tail = newNode;
    }
    else
    {
        // non empty list
        // assuming that the element is present

        Node * curr = tail;
        while(curr->data!=element)
        {
           curr =  curr->next;
        }
        // element found -> curr is representing that node
        Node * temp = new Node(d);
        temp->next=curr->next;
        curr->next= temp;
    }
}

// to print the circular list or rather transverse the list
void print(Node *tail)
{
    if(tail==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }

    Node * temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail!=temp);
    cout<<endl;
}

void deleteNode(Node*&tail,int value)
{
    // empty list
    if(tail==NULL)
    {
        return;
    }
    else
    {
        // non- empty list
        // assuming that value is present in the linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data!=value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next= curr->next;

        // if only 1 node is there in the linked list 
        if(curr== prev)
        {
            tail==NULL;
        }
        //>2 Node linked lists
        if( tail==curr)
        {
            tail = prev;
        }
        curr->next= NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;

    insertNode(tail,5,3);
    print(tail);

     insertNode(tail,3,5);
    print(tail);

     insertNode(tail,5,7);
    print(tail);

     insertNode(tail,7,9);
    print(tail);
     
     insertNode(tail,7,11);
     print(tail);

     deleteNode(tail,5);
     print(tail);
    return 0;
}