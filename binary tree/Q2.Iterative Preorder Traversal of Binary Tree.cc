//Q2.Iterative Preorder Traversal of Binary Tree(leetcode 144)


//1st approach Simple Iterative Preorder (with stack)
//  O(n) time and O(n) space
vector<int> preOrder(Node* root) {
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        res.push_back(curr->data);

        if (curr->right != nullptr)
            s.push(curr->right);
        if (curr->left != nullptr)
            s.push(curr->left);
    }

    return res;
}






//2nd approach[Better Approach] Iterative Preorder with Current Pointer (with stack) -
//O(n) time and O(n) space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

    vector<int> res;
    if (root == NULL)
        return res;

    stack<TreeNode*> s;
    TreeNode* curr = root;

    while (!s.empty() || curr != NULL) {
        while (curr != NULL) {
            res.push_back(curr->val);
            if (curr->right)
                s.push(curr->right);
            curr = curr->left;
        }

        if (!s.empty()) {
            curr = s.top();
            s.pop();
        }
    }

    return res;


    }
};
