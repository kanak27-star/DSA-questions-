//Q3. Reverse List In K Groups(leetcode 25)


Node* kReverse(Node* head, int k) {
    if(head==NULL)
    {
        return NULL;
    }

    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) {
        return head;  // Not enough nodes to reverse
    }


    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int cnt=0;

    while(curr!=NULL && cnt<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    if(next!=NULL){
    head->next=kReverse(next,k);}

    return prev;
}
