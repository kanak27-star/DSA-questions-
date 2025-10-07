#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    //This line declares a pointer named next that can point to another object of type Node.


//constructor
    Node(int data)
    {
       this->data=data;
       this->next=NULL;
    }

    //destructor
~Node()
{
    int value=this->data;
    //memory free
    if(this->next!=NULL)
    {
        delete next;
        this->next=NULL;
    }
    cout<<"memory is free for node with data "<<value<<endl;
}

};



void InsertAtHead(Node* &head,int d){
Node *temp=new Node(d);
temp->next=head;
head=temp;
}

void InsertAtTail(Node* &tail,int d){
Node *temp=new Node(d);
tail->next=temp;
tail=tail->next;
}
void InsertAtPosition(Node* &tail,Node* &head,int position,int d)
{
    if(position==1)
    {
        InsertAtHead(head,d);
        return;
    }
    Node *temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    //to insert at last position
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return;
    }
    //creating a node for d
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;

}

void print(Node* &head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteNode(int position,Node* &head)
{
    //deleting first or start node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        //memory space free krdo
        temp->next=NULL;
        delete temp;

    }
    else
    {
        //deleting any middle node or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
   // cout<<node1->next<<endl;

   //head pointed to node1
   Node*head=node1;
   Node*tail=node1;
   print(head);

   //InsertAtHead(head,12);
   InsertAtTail(tail,12);
   print(head);
   //InsertAtHead(head,15);
   InsertAtTail(tail,15);
   print(head);

   InsertAtPosition(tail,head,4,22);
   print(head);

   cout<<"head: "<<head -> data<<endl;
   cout<<"tail: "<<tail -> data<<endl;

   deleteNode(4,head);
   print(head);

    return 0;
}
