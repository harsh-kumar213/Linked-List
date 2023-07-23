#include<iostream>
#include<map>
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

void insertAtTail(Node* &tail,int d)
{
    Node *temp = new Node(d);
    tail->next=temp;
    tail = temp;
}


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

bool detectLoop(Node*head)
{
    if(head==NULL)
    {
        return false;
    }

    map<Node*,bool>visited;
    Node*temp = head;

    while(temp!=NULL)
    {
        if(visited[temp]==true){
        cout<<"present at element"<<temp->data<<endl;
        return true;}
    
    visited[temp]= true;
    temp = temp ->next;
    }
    return false;
}

int main()
{
    Node * linkedList = new Node(2);
    Node*head = linkedList;
    Node*tail = linkedList;
     
    insertAtTail(tail,4);
    insertAtTail(tail,6);
    insertAtTail(tail,8);
    insertAtTail(tail,10);
    insertAtTail(tail,12);

    
    tail->next = head->next;
      
     bool ans = detectLoop(head);
     if(ans==true)
     {
        cout<<"cycle is present"<<endl;
     }
     else{
        cout<<"not present"<<endl;
     }

    return 0;
}