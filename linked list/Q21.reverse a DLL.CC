//Q21.reverse a DLL(GFG/STRIVER)


class Solution {
  public:

    DLLNode* reverseDLL(DLLNode* head) {

        DLLNode* prev=NULL;
        DLLNode* curr=head;
        while(curr!=NULL)
        {
            DLLNode* forward=curr->next;
            curr->next=prev;
            curr->prev=forward;
            prev=curr;
            curr=forward;
        }return prev;
    }
};
