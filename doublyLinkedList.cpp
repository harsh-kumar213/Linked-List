#include<iostream>
using namespace std;

// creating a double node

class Node {
     
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor

    Node(int d)
    {
        this->data= d;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
    }

};

void print(Node*& head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node * & head)
{
   Node* temp = head;
   int len = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *& tail,Node *& head,int d)
{

    if(head==NULL)
    {
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }
   else {
     Node * temp = new Node(d);
    
     head->prev = temp;
     temp->next=head;
     head = temp;
    }

}

void insertAtTail(Node * & tail,Node*&head,int d)
{

      if(tail==NULL)
    {
        Node * temp = new Node(d);
        tail = temp;
        head = temp;
    }

     // create a node
      Node * temp = new Node(d);
      tail->next= temp;
      temp->prev = tail;
      tail = temp;
}

//insert At any position

void insertAtPosition( Node*&head ,Node *& tail , int position, int d)
{
     Node* temp = head;
    int count = 1;

    if(position == 1)
    {
        insertAtHead(tail,head,d);
        return;
    }

    while(count<position-1)
    {
        temp = temp->next;
        count++;
   
    }

    
    if(temp->next==NULL)
    {
        insertAtTail(tail,head,d);
             return;
    }

    else{

    Node * temp2 =new Node(d);
    temp2->next=temp->next;
    temp2->prev = temp;
    temp->next->prev = temp2;
    temp->next = temp2;
    }
}

void deleteNode(Node *& head,Node *& tail , int position)
{
    // deleting first node
    if(position==1)
    {
       Node * temp = head;
       temp->next->prev=NULL;
       head = temp;
       temp->next=NULL;
       delete temp;
    }
    else{
         Node* curr = head;
            Node* prev = NULL;
            int cnt=1;
            while(cnt<position)
            {
                prev= curr;
                curr= curr->next;
                cnt++;
            }

            if(curr->next==NULL)
            {
                tail = prev;
            }
           curr->prev=NULL;
           prev->next = curr->next;
           // free the memory of the current
        // the curr should point to the NULL before deletion
          curr->next = NULL;
          delete curr;
    }

}

int main()
{
    
    Node * node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

                                               // if no existing node is there
        // Node * head = NULL;
        // Node* tail = NULL;                                       
    print(head);
    // cout<<getLength(head);

    // insert at head
    insertAtHead(head,tail,16);
    //  insertAtHead(head,14);
    //   insertAtHead(head,12);
    print(head);

    insertAtTail(tail,head,16);
    // insertAtTail(tail,14);
    // insertAtTail(tail,12);

    print(head);

    insertAtPosition(head,tail,2,13);
    print(head);

    deleteNode(head,tail,1);
    print(head);

    cout<<"head : "<<head->data<<endl<<"tail : "<<tail->data<<endl;
    
    return 0;

}