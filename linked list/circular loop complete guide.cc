#include<iostream>
#include<map>
using namespace std;


class Node{
public:
int data;
Node* next;


Node(int data){
this->data=data;
this->next=NULL;}

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

void insertNode(Node* &tail,int element,int d)
{
    //empty list
    if(tail==NULL)
    {
        Node* newNode=new Node(d);
        tail=newNode;
        newNode -> next=newNode;
    }
    else
    {
     //non-empty list
     //assuming that the element is present in the list
     Node* curr=tail;

     while(curr->data!=element)
     {
         curr=curr->next;
     }
     Node* temp=new Node(d);
     temp->next=curr->next;
     curr->next=temp;
     }
}

void print(Node* &tail)
{
    //empty list
    if(tail==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}

void deleteNode(Node* &tail,int value)
{
    //empty list
    if(tail==NULL)
    {
        cout<<"List is empty,please check again"<<endl;
        return;
    }
    else
    {
        //non-empty list

        //assuming that value is present in linked list
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 Node Linked List
        if(curr==prev)
        {
           tail=NULL;
        }
        //>=2 Node Linked List
        else if(tail==curr)
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}
//TC=O(N)     SC=O(1)
bool isCircular(Node* &head)
{
    //empty list
    if(head==NULL)
    {
        return true;
    }

    Node* temp=head->next;
    if(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    /*if(temp==head)
    {
        return true;
    }
    return false;*/
    return (temp==head);
}

//TC=O(n)   SC=O(n)
//(linked list cycle 141)leetcode
bool detectLoop(Node* &head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*,bool> visited;

    Node* temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            cout<<"present on element"<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }return false;
}
//TC=O(n)   SC=O(1)
Node* floydDetectLoop(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow)
        {
            return slow;
        }
    }return NULL;
}
Node* getStartingNode(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node*slow =head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }return slow;
}

void removeLoop(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    Node* startOfLoop = getStartingNode(head);
    Node*temp = startOfLoop;
    while(temp->next!=startOfLoop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    Node* tail=NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

   /* insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    deleteNode(tail,3);
    print(tail);*/

    if(isCircular(tail))
    {
        cout<<"Linked list is circular in nature"<<endl;
    }
    else
    {
        cout<<"Linked list is not circular"<<endl;
    }
}

