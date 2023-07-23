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

// Approach
// 1st- Reverse both the linked lists
// 2nd- Add elements of both the linked lists in order
// 3rd- Add the summed elements in new linked list
// 4th- Reverse the sum linked list and return its head


Node* reverse(Node*head)
{
    Node * prev =NULL;
    Node* curr = head;
  
    while(curr!=NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        

    }
    return prev;
}

void insertAtsumTail(Node*&head,Node*&tail,int val)
{
    Node * temp = new Node(val);
    if(head==NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next= temp;
        tail = temp;
    }
}

Node * sum(Node*head1,Node*head2)
{
   head1 = reverse(head1);
   head2 = reverse(head2);
    Node * temp1 = head1;
    Node * temp2 = head2;
    Node * sumHead=NULL ;
    Node * sumTail = NULL;
    int carry= 0;
    while(temp1!=NULL && temp2!=NULL)
    {
          int add  = temp1->data + temp2->data + carry;
          insertAtsumTail(sumHead,sumTail,(add+carry)%10);
          carry = add/10;
          temp1 = temp2->next;
          temp2 = temp2->next;
    }
    while(temp1!=NULL)
    {
          int add = temp1->data + carry;
          insertAtsumTail(sumHead,sumTail,(add+carry)%10);
         
        
          carry = add/10;
          temp1= temp1->next;
    }
    while(temp2!=NULL)
    {
          int add = temp2->data + carry;
          insertAtsumTail(sumHead,sumTail,(add+carry)%10);
         
        
          carry = add/10;
          temp2= temp2->next;
    }
    while(carry!=0)
    {
        int add = temp2->data + carry;
        insertAtsumTail(sumHead,sumTail,(add+carry)%10);
        carry = add/10;   
    }
  
    return sumHead;

}

int main()
{
    Node * linkedList1 = new Node(4);
    Node * head1 = linkedList1;
    Node * tail1 = linkedList1;
    Node * linkedList2 = new Node(3);
    Node * head2 = linkedList2;
    Node * tail2 = linkedList2;

    insertAtTail(tail1,5);
    insertAtTail(tail2,4);
    insertAtTail(tail2,5);

    print(head1);
    print(head2);

    Node * ans = sum(head1,head2);
    ans = reverse(ans);
    print(ans);
  
    return 0;
}