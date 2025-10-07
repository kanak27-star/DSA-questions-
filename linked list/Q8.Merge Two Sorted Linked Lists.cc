//Q8.Merge Two Sorted Linked Lists(codestudio)(leetcode 21)

#include <bits/stdc++.h>
Node<int>* solve(Node<int>* first, Node<int>* second)
{
    Node<int>* curr1 =first;
    Node<int>* next1=curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = NULL;

    //if first list has only one node,point its next to entire second list
    if (next1 == NULL) {
        curr1->next = curr2;
        return first;
    }


    while(next1!=NULL && curr2!=NULL)
    {
        if((curr2->data>=curr1->data) &&
            (curr2->data<=next1->data))
        {
            //add node in between the first list
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            //update pointerrs
            curr1=curr2;
            curr2=next2;
        }
        else{
            //curr1 and next1 ko aage  bdhanaa pdega
            curr1=next1;
            next1=next1->next;

            if(next1==NULL)
            {
                curr1->next=curr2;
                return first;
            }
        }

    }return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)
        return second;

    if(second==NULL)
        return first;

    if(first->data<=second->data)
         return solve(first,second);

    else
    {
        return solve(second,first);
    }
}


