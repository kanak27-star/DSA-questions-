//Q14.remove  nth  node from end of list(letcode 19)


int getLength(ListNode* head)
{
    int len=0;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }return len;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len=getLength(head);
      int cnt=len-n+1;
      if (cnt == 1) { // removing first node
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }


      int ans=1;
      ListNode* prev=NULL;
      ListNode* curr=head;


      while(ans<cnt && curr!=NULL)
      {
        prev=curr;
        curr=curr->next;
        ans++;

      }prev->next=curr->next;
      return head;
    }
};
