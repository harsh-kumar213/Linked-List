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
// above code is to make a circular linked list
//below is for normal singly linke list
void insertAtTail(Node* &tail,int d)
{
    Node *temp = new Node(d);
    tail->next=temp;
    tail = temp;
}

bool checkCircular(Node*head)
{
    if(head==NULL)
    {
        return true;
    }
    Node * temp = head;
    while(temp!=NULL || temp!=head)
    {
        if(temp->next==NULL)
        {
            return false;
        }
        if(temp->next==head)
        {
            return true;
        }
        temp = temp->next;
    }
}

int main()
{
    Node *tail = NULL;
    Node*empty = NULL;

    insertNode(tail,5,3);
   

     insertNode(tail,3,5);
    

     insertNode(tail,5,7);
    

     insertNode(tail,7,9);
   
     
     insertNode(tail,7,11);
    

    
     

         //new node created
     Node n1(12);

    Node* head2 = &n1;
    Node* tail2 = &n1;
    insertAtTail(tail2,14);
    insertAtTail(tail2,16);

    bool ans = checkCircular(tail);
    bool ans2 = checkCircular(head2);
    bool ans3 = checkCircular(empty);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    return 0;
}