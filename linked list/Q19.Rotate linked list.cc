//Q19.Rotate linked list(leetcode 61)


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==NULL || head->next==NULL)
       {
        return head;
       }
       ListNode* temp=head;
       int cnt=1;
       while(temp->next!=NULL)
       {
        temp=temp->next;
        cnt++;
       }
       temp->next=head;
       temp=head;
       for(int i=1;i<cnt-(k%cnt);i++)
       {
        temp=temp->next;
       }
       head=temp->next;
       temp->next=NULL;
       return head;
    }
};
