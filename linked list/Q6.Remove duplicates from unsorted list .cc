//Q6.Remove duplicates from unsorted list (codestudio)



#include <bits/stdc++.h>
#include <unordered_map>

Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    unordered_map<int,bool>visited;
    Node *curr = head;
    Node* prev=NULL;
    while(curr!=NULL)
    {
        if(visited[curr->data])
        {
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else
        {
            visited[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }return head;

}
