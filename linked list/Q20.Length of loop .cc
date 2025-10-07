//Q20.Length of loop (striver ,gfg)



Node* checkLoop(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            return slow;
        }
    }return NULL;

}
Node* getStartingNode(Node* head)
{
    Node* intersection=checkLoop(head);
    Node* slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    if(slow==intersection)
    {
        return slow;
    }return NULL;
}

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        //Node* intersection=checkLoop(head);
        if(checkLoop(head)!=NULL)
        {
            Node* temp=getStartingNode(head);
            Node* getStart=temp;
            int cnt=1;
            while(getStart->next!=temp)
            {
                getStart=getStart->next;
                cnt++;
            }
            return cnt;
        }
        else
        {
            return 0;
        }
    }
};


//Q.search a key(gfg)
class Solution {
  public:
    bool searchKey(int n, Node* head, int key) {
        Node* temp=head;
        while(temp!=NULL )
        {
            if(temp->data==key)
            {
                return true;
            }
            temp=temp->next;
        }return false;
    }
};

