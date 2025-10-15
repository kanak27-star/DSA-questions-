//faang question part2
// Q1. zig-zag traversal(this question is present on leetcode also)
class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
       vector <int> result;
       if(root==NULL)
           return result;
        queue <Node*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int size=q.size(); //this will tell no of layers
            vector <int>ans(size);

            //level process
            for(int i=0;i<size;i++)
            {
                Node* frontNode = q.front();
                q.pop();

                //normal insert or reverse insert
                int index=leftToRight? i:size-i-1;
                ans[index]=frontNode->data;

                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            //direction change krni h
            leftToRight =!leftToRight;

            for(auto i:ans)
            {
                result.push_back(i);
            }

        }


    }
};



//Q2 tree boundary traversal
class Solution {
  public:
    void traverseLeft(Node* root,vector<int>& ans)
    {
        if(root==NULL || root->left==NULL && root->right==NULL)
        {
            return;
        }
        ans.push_back(root->data);
        if(root->left)
           traverseLeft(root->left,ans);
        else
           traverseLeft(root->right,ans);
    }
    void traverseLeaf(Node* root,vector<int>& ans)
    {
        if(root==NULL)
           return;

        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);

    }

    void traverseRight(Node* root,vector<int>& ans)
    {
       if(root==NULL || root->left==NULL && root->right==NULL)
        {
            return;
        }
        if(root->right)
            traverseRight(root->right,ans);
        else
            traverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector <int> ans;
        if (root==NULL)
           return ans;
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        traverseRight(root->right,ans);

    }
};

// Q3. vertical order traversal
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,map<int,vector<int>>> nodes;
        queue <pair<Node*,pair<int,int>>>q;
        vector<vector<int>> ans;

        if(root==NULL)
          return ans;

        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if(frontNode->left)
                 q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));

             if(frontNode->right)
                 q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
        // for(auto i:nodes)
        // {
        //     for (auto j:i.second)
        //     {
        //         for(auto k:j.second)
        //         {
        //             ans.push_back({k});
        //         }
        //     }
        // }

        for (auto i : nodes) {
            vector<int> col;               // one column
              for (auto j : i.second) {
                 for (auto k : j.second) {
                    col.push_back(k);      // collect all nodes in this column
        }
    }
    ans.push_back(col);            // push full column into result
}
        return ans;


    }
};

//Q4 top view
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector <int>ans;
        if(root==NULL)
        {
            return ans;
        }
        map <int,int> topNode;
        queue <pair<Node*,int>>q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();

             Node* frontNode=temp.first;
             int hd=temp.second;

             if(topNode.find(hd)==topNode.end())
                  topNode[hd]=frontNode->data;

             if(frontNode->left)
                 q.push(make_pair(frontNode->left,hd-1));

             if(frontNode->right)
                 q.push(make_pair(frontNode->right,hd+1));
        }
    }
};

//5.bottom view


class Solution {
  public:
    vector<int> bottomView(Node *root) {

        vector<int> ans;
         if(root==NULL)
           return ans;

         map<int,int> topNode;
         queue <pair<Node*,int>> q;

         q.push(make_pair(root,0));

         while(!q.empty())
         {
            pair<Node*,int>temp =q.front();
            q.pop();

            Node* frontNode=temp.first;
            int hd=temp.second;


                topNode[hd]=frontNode->data;

            if(frontNode->left)
                 q.push(make_pair(frontNode->left,hd-1));

            if(frontNode->right)
                 q.push(make_pair(frontNode->right,hd+1));
         }


         for(auto i:topNode)
         {
           ans.push_back(i.second);}

         return ans;


    }
};

//6.left view //7.right view

//Q8. Sum of nodes on the longest path
void solve(Node *root,int sum,int &maxSum,int len,int &maxLen)
{
    if(root==NULL)
    {
         if(len>maxLen)
         {
             maxLen=len;
             maxSum=sum;
         }
         if(len==maxLen)
         {
             maxSum=max(sum,maxSum);
         }
         return;
    }
    sum=sum+root->data;

    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}

class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
       int len=0;
       int maxLen=0;

       int sum=0;
       int maxSum=INT_MIN;

       solve(root,sum,maxSum,len,maxLen);

       return maxSum;

    }
};

//Q9.LCA
class Solution {
  public:

    Node* lca(Node* root, int n1, int n2) {

        if(root==NULL)
        {
            return NULL;
        }
        if(root->data==n1 || root->data==n2)
        {
            return root;
        }

        Node* leftAns = lca(root->left,n1,n2);
        Node* rightAns = lca(root->right,n1,n2);

        if(leftAns!=NULL && rightAns!=NULL)
           return root;
        if(leftAns!=NULL && rightAns==NULL)
           return leftAns;
        if(leftAns==NULL && rightAns!=NULL)
           return rightAns;
        if(leftAns==NULL && rightAns==NULL)
           return NULL;
    }
};




//Q10.K Sum Paths

void solve(Node *root, int k,int &count, vector<int> path)
{
   //base case
   if(root==NULL)
      return;

   path.push_back(root->data);

   //left
   solve(root->left,k,count,path);
   //right
   solve(root->right,k,count,path);

   //check for k sum
   int size=path.size();
   int sum=0;
   for(int i=size-1;i>=0;i--)
   {
       sum+=path[i];
       if(sum==k)
         count++;
   }
   path.pop_back();
}
class Solution {
  public:
    int sumK(Node *root, int k) {
        vector<int> path;
        int count=0;
        solve(root,k,count,path);
        return count;
    }
};


//Q11.Kth Ancestor in a Tree

Node* solve(Node *root, int &k, int node, bool &found) {
    if (root == NULL) return NULL;

    if (root->data == node) {
        found = true;
        return root;
    }

    Node* leftAns = solve(root->left, k, node, found);
    Node* rightAns = solve(root->right, k, node, found);

    if (leftAns != NULL || rightAns != NULL) {
        k--;
        if (k == 0) return root;  // kth ancestor found
        return leftAns ? leftAns : rightAns;
    }

    return NULL;
}

class Solution {
  public:
    int kthAncestor(Node *root, int k, int node) {
        bool found = false;
        Node* ans = solve(root, k, node, found);
        if (!found || ans == NULL || ans->data == node) return -1;
        return ans->data;
    }
};

//Q12.Maximum sum of Non-adjacent nodes

pair<int,int> solve(Node *root)
{
    if(root==NULL)
    {
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=solve(root->left);
    pair<int,int> right=solve(root->right);
    pair<int,int> res;

    res.first=root->data+left.second+right.second;
    res.second=max(left.first,left.second)+max(right.first,right.second);
    return res;
}

class Solution {
  public:
   int getMaxSum(Node *root) {
       pair<int,int> ans=solve(root);
       return max(ans.first,ans.second);
    }
};



