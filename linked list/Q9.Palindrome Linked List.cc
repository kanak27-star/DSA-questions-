//Q9.Palindrome Linked List(gfg)
(leetcode 234)

//approach1
/*algo(TC-O(n)  SC-O(1))
1.Create an array
2.Copy Linked List content into array
3.Write logic to check palindrome or not */

//TC=O(n)  SC=O(n)
#include<vector>
bool checkPalindrome(vector<int>arr)
{
    int n=arr.size()-1;
    int s=0;
    int e=n;

    while(s<=e)
    {
        if(arr[s]!=arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }return 1;
}
class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
       vector<int>arr;
       Node* temp =head;
       while(temp!=NULL)
       {
           arr.push_back(temp->data);
           temp=temp->next;
       }
       return checkPalindrome(arr);

    }
};

//approach2

/*algo   (TC-O(n)  SC-O(n))
1. find middle
2. reverse linked list after it
3. compare both halves
4. repeat 2nd step*/

Node* getMid(Node *head)
{
     Node *slow=head;
     Node *fast=head->next;
     while(fast!=NULL && fast->next!=NULL)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
     return slow;
}
Node* reverse(Node *head)
{
  Node* curr= head;
  Node* prev=NULL;
  while(curr!=NULL)
  {
      Node* forward=curr->next;
      curr->next=prev;
      prev=curr;
      curr=forward;
  }return prev;
}

class Solution {
  public:

    bool isPalindrome(Node *head) {
       if(head->next==NULL)
       {
           return true;
       }
       //step1->find middle
       Node* middle =getMid(head);

       //step2->reverse list after  middle
       Node* temp=middle->next;
       middle->next= reverse(temp);

       //step3->compare both halves
       Node* head1=head;
       Node* head2=middle->next;

       while(head2!=NULL)
       {
           if(head1->data!=head2->data)
           {
               return false;
           }
           head1=head1->next;
           head2=head2->next;
       }

       //step4:repeat step2
       temp=middle->next;
       middle->next= reverse(temp);
       return true;
     }
};




