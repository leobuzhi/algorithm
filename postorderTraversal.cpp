/*
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
//my Solution 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==nullptr)
            return ret;
        unordered_map<TreeNode*,bool> um;
        TreeNode* node=root;
        stack<TreeNode*> nodes;
        nodes.push(node);
        while(!nodes.empty())
        {
            node=nodes.top();
            if((node->left&&!um[node->left])||(node->right&&!um[node->right]))
            {
                if(node->right&&um[node->right]==0)
                    nodes.push(node->right);
                if(node->left&&um[node->left]==0)
                    nodes.push(node->left);
            }else{
                ret.push_back(node->val);
                um[node]=true;
                nodes.pop();
            }
        }
        return ret;
    }
};
