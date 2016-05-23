/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
//Breadth-first-search
class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            ++res;
            for (int i = 0, n = q.size(); i < n; ++i)
            {
                TreeNode *p = q.front();
                q.pop();

                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
        }

        return res;
    }
};
