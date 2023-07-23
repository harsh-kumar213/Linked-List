#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;

    Node(int d)
    {
        this->data = d;
        this->next =NULL;
    }
};
void insertAtTail(Node*&tail,int d)
{
    Node * temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node * head)
{
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<endl;
}

Node * merge(Node*head1,Node*head2)
{
    // if first list is NULL
    if(head1 == NULL)
      return head2;
    // if second list is NULL
    if(head2==NULL)
      return head1;

    // if only one element is present in first lis
    if(head1->next==NULL)
    {
        head1->next = head2;
        return head1;
    }

    // if both are not empty
    Node* curr = head1->next;
    Node* prev = head1;
    
    Node* temp = head2;
    while(curr!=NULL && temp!=NULL)
    {
     
      
            Node * forward = temp->next;
            // checking if the element can fit in between curr and prev
            if(temp->data<=curr->data && temp->data>=prev->data)
            {
                // added the node to the list
                temp->next = curr;
                prev->next = temp;
                // updating the pointers
                prev  = temp;
                temp = forward;
                 

            }
            // element does not lie in between 
            else
            {
               prev  = curr;
               curr= curr->next; 
               
               if(curr==NULL)
                 prev->next = temp;
            }
            
        
    }
  
    return head1; 
}

int main()
{
    // all the pointers for the linked list
    Node * linkedList1 = new Node(1);
    Node * head1 = linkedList1;
    Node * tail1 = linkedList1;
    Node * linkedList2 = new Node(2);
    Node * head2 = linkedList2;
    Node * tail2 = linkedList2;
    Node * Head = NULL;


    // inserting elements in the first linked list
    insertAtTail(tail1,3);
    insertAtTail(tail1,5);

    // inserting elements in the second linked list
    insertAtTail(tail2,4);
    insertAtTail(tail2,5);

    print(head1);
    print(head2);

    // which linked list have greater first element
    if(head1->data>=head2->data)
      Head = merge(head2,head1);

    else
      Head = merge(head1,head2);  
    
    print(Head);

    return 0;
}