//Q11.Clone List with Next and Random(gfg && leetcode 138)

//approach1
void InsertAtTail(Node* &head,Node* &tail,int d)
{
    Node* temp=new Node(d);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        //step1 : crerate a clone list
        Node* cloneHead=NULL;
        Node* cloneTail= NULL;

        Node* temp=head;
        while(temp!=NULL)
        {
            InsertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }

        //step2:Create a map
        unordered_map<Node*,Node*>oldToNewNode;

        Node* originalNode=head;
        Node* cloneNode =cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL)
        {
            oldToNewNode[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;

        while(originalNode!=NULL)
        {
            cloneNode->random=oldToNewNode[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;

    }
};




//approach2
unable to understand the next approach code


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
void insertCopyInBetween(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* nextElement=temp->next;
        Node* copy=new Node(temp->val);

        copy->next=nextElement;
        temp->next=copy;

        temp=nextElement;
    }
}

void connectRandomPointers(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* copyNode=temp->next;
        if(temp->random)
        {
            copyNode->random=temp->random->next;
        }
        else
        {
            copyNode->random=NULL;
        }
        temp=temp->next->next;
    }
}
Node* getDeepCopyList(Node* head){
    Node* temp=head;
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(temp!=NULL)
    {
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }return dummyNode->next;
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
