//Q10.Add Number Linked Lists(gfg)
//           OR
//add two numbers(leetcode2)


/* it can be viewed as 2 types of questions
1-> Add 2 number represented by linked list
2->add 1 to a number represented by linked list

now here the steps to carry out add
1. carry=0
2. sum find
3. digit find (digit=sum%10)
4. create node for digit
5. carry nikalo = carry = sum/10*/




Node* reverse(Node* head)
{
   Node* prev=NULL;
   Node* curr=head;

   while(curr!=NULL)
   {
    Node* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
   }return prev;
}
void insertAtTail(Node* &head, Node* &tail,int val)
{
    Node* temp =new Node(val);
    //empty list
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;

    }
    else
    {
        tail->next=temp;
        tail=temp;
    }


}
Node*add(Node* first, Node* second)
{
    int carry=0;

    Node* ansHead=NULL;
    Node* ansTail=NULL;

    while(first!=NULL || second!=NULL || carry!=NULL)
    {
        int val1=0;
        if(first!=NULL)
            val1=first->data;

        int val2=0;
        if(second!=NULL)
            val2=second->data;



        int sum= carry+val1+val2;
        int digit=sum%10;
        //create node and add answer in linked list
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        if(first!=NULL)
           first=first->next;
        if(second!=NULL)
           second=second->next;
    }
   return ansHead;
}

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        //step1 -> reverse input LL
        Node* first = reverse( num1);
        Node* second= reverse( num2);

        //step2 -> add 2 LL
        Node* ans= add(first,second);

        //step3
        ans = reverse(ans);

        // Step 4: Remove leading zeros
        while (ans != nullptr && ans->data == 0 && ans->next != nullptr) {
            Node* temp = ans;
            ans = ans->next;
            delete temp;
        }

        return ans;

    }
};
