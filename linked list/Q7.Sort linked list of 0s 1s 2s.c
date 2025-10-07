//Q7.Sort linked list of 0s 1s 2s(codestudio)

//approach1

Node* sortList(Node *head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount =0;

    Node* temp =head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zeroCount++;
        }
        else if(temp->data==1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }temp=temp->next;
    }

    temp=head;
    while(temp!=NULL)
    {
        if(zeroCount!=0)
        {
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0)
        {
            temp->data=1;
            oneCount--;
        }
        else
        {
            temp->data=2;
            twoCount--;
        }temp=temp->next;
    }return head;
}


//approach2


void InsertAtTail(Node* &tail,Node* curr)
{
    tail->next=curr;
    tail=curr;
}
Node* sortList(Node *head){
    Node* zeroHead= new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead= new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead= new Node(-1);
    Node* twoTail = twoHead;

    Node* curr  = head;

    //create seperate list of 0s,1s and 2s
    while(curr!=NULL)
    {
       int value = curr->data;

       if(value==0)
       {
           InsertAtTail(zeroTail,curr);
       }

       else if(value==1)
       {
           InsertAtTail(oneTail,curr);
       }

       else if(value==2)
       {
           InsertAtTail(twoTail,curr);
       }
       curr=curr->next;
    }

    //merge 3 sublist

    //1s list not empty
    if(oneHead->next!=NULL)
    {
        zeroTail->next=oneHead->next;
    }
    else
    {
        //1s list->empty
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next = NULL;

    //setup head
    head=zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

TC-O(n)   SC-O(1)
