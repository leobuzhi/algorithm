/*Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/







/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    vector<int> tmp;
    if (root == nullptr)
        return result;
    if (root)
    {
        result.push_back(root->val);
    }
    if (root->left || root->right)
    {
        if (root->left)
        {
            tmp=preorderTraversal(root->left);
            result.insert(result.end(), tmp.begin(),tmp.end());
        }
        if (root->right)
        {
            tmp = preorderTraversal(root->right);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
    }
    return result;
}
};



//another Solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root==NULL)
                return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* node= nodeStack.top();
            result.push_back(node->val);
            nodeStack.pop();
            if(node->right)
                nodeStack.push(node->right);
            if(node->left)
                nodeStack.push(node->left);
        }
        return result;

    }
};
