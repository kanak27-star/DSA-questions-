//Q4.To detect and remove loop


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
    if (intersection == NULL)
    {
        return NULL;  // No loop found
    }
    Node* slow =head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }return slow;
}

Node *removeLoop(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL) {
        // No loop detected
        return head;
    }

    Node*temp = startOfLoop;
    while(temp->next!=startOfLoop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
