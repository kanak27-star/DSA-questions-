//Q13.Delete the middle node of a linked list(leetcode 2095)


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast  && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return head;
    }
};
