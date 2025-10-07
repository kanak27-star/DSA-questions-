//Q5.Remove duplicates from sorted list (leetcode 83),(codestudio)



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
  if(head==nullptr)
   {
       return  nullptr;
   }
   ListNode* curr=head;
   while(curr!=nullptr)
   {
       if(curr->next!=nullptr && curr->val==curr->next->val)
       {
          ListNode* next_next = curr->next->next;
          ListNode* nodeToDelete = curr->next;
          //we have delete before assigning the value of curr->next because otherwise we will
          //loose track of the nodeToDelete
          delete (nodeToDelete);
          curr->next = next_next;

       }
       else
       {
           curr=curr->next;
       }
   }return head;
    }
};
