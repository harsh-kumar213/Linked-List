#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
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
    cout<<endl;
}

Node * findMid(Node * head)
{
    Node * slow  = head;
    Node * fast =  head;
    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL)
          fast = fast->next;
    }
    return slow;
}

Node * merge(Node* head1,Node*  head2)
{
    // if first is empty
    if(head1==NULL)
      return head2;
    // if second is empty  
    if(head2==NULL)
      return head1;
    
    Node * ans = new Node(-1);
    Node * temp = ans;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            temp ->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
     while(head1 != NULL) {
        temp -> next = head1;
        temp = head1;
        head1 = head1 -> next;
    }
    
    while(head2 != NULL) {
        temp -> next = head2;
        temp = head2;
        head2 = head2 -> next;
    }
    
    ans = ans -> next;
    return ans;
 

}

Node * mergeSort(Node * head)
{
    // base case
    if(head==NULL || head->next==NULL){
       return head;}
    
    // break linked list into two parts
    Node * mid = findMid(head);
    Node * left = head;
    Node * right = mid->next;
    mid->next = NULL;

    // sort by recursive calls 
    // As it will keep on breaking till it gets one and one element is always sorted]
    left = mergeSort(left);
    right = mergeSort(right);
    // merge both left and right halve

    
    Node *  result = merge(left,right);
    
    return result; 
}

int main()
{
    Node * linkedList = new Node(3);
    Node * head = linkedList;
    Node * tail = linkedList;
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,5);
    insertAtTail(tail,4);
    print(head);
    Node *  ans = mergeSort(head);
    print(ans);
     
    return 0;            
}