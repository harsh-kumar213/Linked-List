#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

     // constructor
     Node(int data)
     {
        this->data=data;
        this->next=NULL;
     }
};

// insert at the head

void insertAtHead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}

// insert in middle

void insertAtPosition(Node* &head,Node * & tail,int position,int d)
{
    Node* temp = head;
    int count = 1;

    if(position == 1)
    {
        insertAtHead(head,d);
        return;
    }

    while(count<position-1)
    {
        temp = temp->next;
        count++;
   
    }

    
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
             return;
    }

    else{

    Node * temp2 =new Node(d);
    temp2->next=temp->next;
    temp->next=temp2;
    }
}

// insert at the tail

void insertAtTail(Node* &tail,int d)
{
    Node *temp = new Node(d);
    tail->next=temp;
    tail = temp;
}

// deleting a node

void deleteNode(Node * &head,Node *&tail,int position)
{
       if(position == 1)
       {
          Node * temp = head;
          head = head->next;

          // free the memory of the start node
          temp ->next= NULL;
          delete temp;

       }

       else
       {
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

           prev->next = curr->next;
           // free the memory of the current
        // the curr should point to the NULL before deletion
          curr->next = NULL;
          delete curr;

       }
}

// print the linked list

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

int main()
{
    //new node created
     Node n1(12);

    Node* head = &n1;
    Node* tail = &n1;
    insertAtTail(tail,14);
    insertAtTail(tail,16);
    print(head);
    insertAtPosition(head,tail,1,11);
    insertAtPosition(head,tail,3,15);
  
      print(head);
  // deleting nodes
     cout<<endl<<"after deletion"<<endl<<endl;
    deleteNode(head,tail,5);  
    print(head);

    cout<<head->data<<endl;
    cout<<tail->data<<endl;
     
    
    return 0;
}