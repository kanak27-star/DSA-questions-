//Q2. Middle Of Linked List(codestudio )
//also present in leetcode      Q 876 Middle Of Linked List



int getLength(Node *head)
{
    Node *temp = head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }return len;
}
Node *findMiddle(Node *head) {
    int length=getLength(head);
    int ans=length/2;

    Node *temp = head;
    int cnt=0;
    while(cnt<ans)
    {
        temp=temp->next;
        cnt++;
    }return temp;
}

