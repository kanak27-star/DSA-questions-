//Q1. Reverse Linked List(codestudio & leetcode)


Node* reverseLinkedList(Node* head)
{
if(head==NULL||head->next=NULL)
{
return head;
}
Node* prev=NULL;
Node* curr=head;
Node* forward=NULL;
while(curr!=NULL)
{
forward=curr->next;
curr->next=prev;
prev=curr;
curr=forward;
}
return prev;
}
//time complexity->O(n)  {n is the no of nodes}
//space complexity->O(1)


//approach2
void reverse(LinkedListNode<int> *&head,LinkedListNode<int> * curr,LinkedListNode<int> * prev)
{
    if(curr==NULL)
    {
        head=prev;
        return;
    }
    LinkedListNode<int> *forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    reverse(head,curr,prev);
    return head;
}




