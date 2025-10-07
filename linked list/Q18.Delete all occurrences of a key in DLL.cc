//Q18.Delete all occurrences of a key in DLL(striver)

class Solution {
   public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val==target)
            {
                if(temp==head)
                {
                    head=head->next;
                }
                ListNode* prevNode=temp->prev;
                ListNode* nextNode=temp->next;
                if(prevNode)  prevNode->next=nextNode;
                if(nextNode)  nextNode->prev=prevNode;
                free(temp);
                temp=nextNode;
            }
            else
            {
                temp=temp->next;
            }
        }return head;
    }
};
