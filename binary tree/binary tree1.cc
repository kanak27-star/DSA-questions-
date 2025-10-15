//  Q1 No of leaf nodes

void inorder(BinaryTreeNode<int> *root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL)
    {
       count++;

    }
    inorder(root->right,count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    inorder(root,cnt);
    return cnt;

}



//  Q2. Height of binary tree
class Solution {
  public:
    int height(Node* node) {
       if(node==NULL)
       {
           return -1;
       }
       int left=height(node->left);
       int right=height(node->right);
       int ans=max(left,right)+1;
       return ans;

    }
};


// Q3 Diameter of a binary tree
//approach 1->this approach gives TLE
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int maxHeight=max(left,right)+1;
    return maxHeight;
}
class Solution {
  public:
    int diameter(Node* root) {
        if(root==NULL)
        {
            return 0;
        }
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right)+1;
        int ans=max(op1,max(op2,op3));
        return ans;

    }
};

//approach 2 (optimized solution)
class Solution {
  public:
    pair<int,int>diameterFast(Node* root) {
        if(root==NULL)
        {
               pair<int,int> p=make_pair(0,0);
               return p;
        }
        pair<int,int>left=diameterFast(root->left);
        pair<int,int>right=diameterFast(root->right);

        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;

        pair <int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;

    }
    int diameter(Node* root) {
        return diameterFast(root).first;

    }
};

// Q3 To check Balanced tree or not
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int maxHeight=max(left,right)+1;
    return maxHeight;
}

class Solution {
  public:
    bool isBalanced(Node* root) {
        // Code here
        if(root==NULL)
        {
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(left&& right&&diff)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


//method 2

class Solution {
  public:
    pair<bool,int>isBalancedFast(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> p =make_pair(true,0);
            return p;
        }
        pair <bool,int> left=isBalancedFast(root->left);
        pair <bool,int> right=isBalancedFast(root->right);

        bool leftAns=left.first;
        bool rightAns=right.first;
        bool diff=abs(left.second-right.second)<=1;

        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;

        if(leftAns && rightAns && diff)
        {
            ans.first=true;
        }
        else
        {
            ans.first=false;
        }return ans;
    }

    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
    }
};

// Q4 Tee identical or not
class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        if(r1==NULL && r2==NULL)
        {
            return true;
        }
        if(r1!=NULL && r2==NULL)
        {
            return false;
        }
        if(r1==NULL && r2!=NULL)
        {
            return false;
        }

    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);
    bool value=r1->data==r2->data;
    if(left && right &&value)
    {
    return true;}
    else
    {return false;}

    }
};


//Q5. Sum Tree or not
class Solution {
  public:
    pair<bool,int>isSumTreeFast(Node* root)
    {
       if(root==NULL)
       {
           pair<bool,int>p=make_pair(true,0);
           return p;
       }
       if(root->left==NULL && root->right==NULL)
       {
           pair<bool,int>p=make_pair(true,root->data );
           return p;
       }
       pair <bool,int> leftAns=isSumTreeFast(root->left);
       pair <bool,int> rightAns=isSumTreeFast(root->right);

       bool isLeftSumTree=leftAns.first;
       bool isRightSumTree=rightAns.first;
       bool condn = (leftAns.second +rightAns.second)==root->data;

       pair<bool,int>ans;

       if(isLeftSumTree &&isRightSumTree && condn)
       {
           ans.first=true;
           ans.second=2*root->data;
       }
       else
       {
           ans.first=false;
       }return ans;

    }
    bool isSumTree(Node* root) {
        return isSumTreeFast(root).first;
    }
};
