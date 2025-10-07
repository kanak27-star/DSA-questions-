//Q17.Remove duplicates from a sorted doubly linked list
(gfg)


class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {

        Node *curr=head;
        while(curr!=NULL  && curr->next!=NULL )
        {
            if(curr->data==curr->next->data)
            {
                Node *next_next=curr->next->next;
                Node *nodeToDelete=curr->next;
                delete nodeToDelete;
                curr->next=next_next;
                if (next_next != NULL)
                {
                    next_next->prev = curr;
                }
            }
            else
            {
                curr=curr->next;
            }

        }return head;
    }
};
