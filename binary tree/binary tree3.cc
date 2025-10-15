//Q1.Construct Tree from Inorder & Preorder(gfg)

int findPosition(vector<int> &inorder,int element,int n)
{
    for(int i=0;i<n;i++)
    {
        if(inorder[i]==element)
        {
            return i;
        }
    }return -1;
}


Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,
int inorderStart,int inorderEnd,int n)
{
    //base cae
    if(index>=n || inorderStart>inorderEnd)
    {
        return NULL;
    }

    int element=preorder[index++];
    Node* root = new Node(element);
    int position=findPosition(inorder,element,n);

    //recursive calls
    root->left=solve(inorder,preorder,index,inorderStart,position-1,n);
    root->right=solve(inorder,preorder,index,position+1,inorderEnd,n);

    return root;


}
class Solution {
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex=0;
        int n=inorder.size();
        Node* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n);
        return ans;
    }
};



//optimized code with a little bit of changes
void createMapping(vector<int> &inorder,map<int,int> &nodeToIndex,int n)
{
    for(int i=0;i<n;i++)
    {
        nodeToIndex[inorder[i]]=i;
    }
}


Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,
int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex)
{
    //base cae
    if(index>=n || inorderStart>inorderEnd)
    {
        return NULL;
    }

    //create a root node for element
    int element=preorder[index++];
    Node* root = new Node(element);

    //find elements index in inorder
    int position=nodeToIndex[element];

    //recursive calls
    root->left=solve(inorder,preorder,index,inorderStart,position-1,n,nodeToIndex);
    root->right=solve(inorder,preorder,index,position+1,inorderEnd,n,nodeToIndex);

    return root;


}
class Solution {
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex=0;
        int n=inorder.size();
        map<int,int> nodeToIndex;
        //create nodes to index mapping
        createMapping(inorder,nodeToIndex,n);
        Node* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};



//Q2. minm time to burn a tree

class Solution {
  public:
      //create mapping
      //return target node
    Node* createParentMapping(Node* root, int target,
    map<Node*,Node*> &nodeToParent)
    {
         Node* res=NULL;

         queue<Node*> q;
         q.push(root);

         while(!q.empty())
         {
             Node* front = q.front();
             q.pop();

             if(front->data==target)
             {
                 res=front;
             }

             if(front->left)
             {
                 nodeToParent[front->left]=front;
                 q.push(front->left);
             }

              if(front->right)
             {
                 nodeToParent[front->right]=front;
                 q.push(front->right);
             }
         }
         return res;

    }
    int burnTree(Node* root,map<Node*,Node*> &nodeToParent){
        map<Node*,bool>visited;
        queue<Node*> q;

        q.push(root);
        visited[root]=true;

        int ans=0;

        while(!q.empty())
        {
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                 Node* front = q.front();
                 q.pop();


            if(front->left && !visited[front->left])
            {
                 flag=1;
                 q.push(front->left);
                 visited[front->left]=true;
            }

            if(front->right && !visited[front->right])
            {
                 flag=1;
                 q.push(front->right);
                 visited[front->right]=true;
            }

            if(nodeToParent[front]  &&  !visited[nodeToParent[front]])
            {
                flag=1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=true;
            }

        }
        if(flag==1)
        {
            ans++;
        }

        } return ans;
    }
    int minTime(Node* root, int target) {
        //algo
        //step1:create nodeToParent mapping
        //step2:find target node
        //step3:burn the tree in min time


        map<Node*,Node*>nodeToParent;
        Node* targetNode = createParentMapping(root,target,nodeToParent);

         int ans= burnTree(targetNode,nodeToParent);
        return ans;

    }
};


//Q3.Flatten binary tree to linked list

// User function Template for C++

class Solution {
  public:
    void flatten(Node *root) {
        Node* curr=root;
        while(curr!=NULL)
        {
            if(curr->left)
            {
                Node* pred=curr->left;
                while(pred->right!=NULL)
                {
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            else
            {
                curr=curr->right;
            }
        }

    }
};
