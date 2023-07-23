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
/*
// Approach - 1
// 1st - create an array
// 2nd - copy the content of the linked list in the array
// 3rd - check whether the array is an palindrome

bool checkPaindrome(Node*head)
{
    int arr[20];
    Node* temp = head;
    int i = 0;
    int count = 0;
    while(temp!=NULL)
    { 
        arr[i] = temp->data;
        temp = temp->next;
        i++;
        count++;
    }
    // we got the array and the length
    i = 0 ;
    int j = count -1 ;
    // checking if the array is a paindrome
    while(i<=j)
    {
        if(arr[i]== arr[j])
        {
             i++;
             j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
*/

// Approach - 2

// 1st- Find the middle of the linked list
// 2nd- Reverse the second half of the linked list
// 3rd- Compare both halfs
// 4th- Repeat 2nd to get original linked list

Node *reverse(Node*head,Node*curr,Node*prev)
{
    if(curr==NULL)
    {
        return prev;
    }

    Node* forward = curr->next;
    head = reverse(head,forward,curr);
    curr->next=prev;
    return head;
}

bool checkPalindrome(Node* head)
{
    Node* temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    int i = 1;
    temp= head;
    while(i<=(count/2))
    {
        temp=temp->next;
    }
    Node * prev = NULL;
    Node * curr=  temp->next;
    Node * head2 = reverse(temp->next,curr,prev);
    i= 1;
    while(i<=(count/2))
    {
        if(head->data!=head2->data)
          return false;

        head = head->next;
        head2=head2->next; 
    }
    return true;
}



int main()
{
    Node * linkedList = new Node(1);
    Node * head = linkedList;
    Node * tail = linkedList;

    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    
    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome)
      cout<<"it is a palindrome"<<endl;
    else
      cout<<"it is not a palindrome"<<endl;

    return 0;
}