#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        this->data = d;
        this->next=NULL;
    }
};

void insertAtTail(Node* &tail,int d)
{
    Node * temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node * head)
{
    int count = 0;
    Node * temp = head;

    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// approach 1

void getMiddle(Node*head,int length)
{
    int mid = (length/2)+1;
    int count = 1;
    while(count<mid)
    {
        head = head->next;
        count++;
    }
    cout<<head->data<<endl;
}



int main()
{
    Node *n1 = new Node(10);
    Node * head = n1;
    Node* tail = n1;

    insertAtTail(tail,12);
    insertAtTail(tail,14);
    insertAtTail(tail,16);
    
    print(head);

    // approach 1 - length wise approach
    int length =  getLength(head);
    getMiddle(head,length);
    return 0;
}