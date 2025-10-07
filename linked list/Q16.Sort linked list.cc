//Q16.Sort linked list(leetcode148)

ListNode*  getMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* first,ListNode* second)
{
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }
    ListNode* ans= new ListNode(-1);
    ListNode* temp=ans;
    while(first!=NULL && second!=NULL)
    {
      if(first->val<=second->val)
    {
        temp->next=first;
        temp=first;
        first=first->next;
    }
    else
    {
        temp->next=second;
        temp=second;
        second=second->next;
    }


    }

    while(first!=NULL)
    {
        temp->next=first;
        temp=first;
        first=first->next;
    }

    while(second!=NULL)
    {
       temp->next=second;
        temp=second;
        second=second->next;
    }
  ans=ans->next;
  return ans;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* mid=getMid(head);
        ListNode* first=head;
        ListNode* second=mid->next;
        mid->next=NULL;

        first=sortList(first);
        second=sortList(second);
        ListNode* ans=merge(first,second);
        return ans;
    }
};
