/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       if(nums.empty())
          return nullptr;
       if(nums.size()==1)
          return new TreeNode(nums[0]);
       int mid=nums.size()/2;
       TreeNode* ret=new TreeNode(nums[mid]);
       vector<int> left(nums.begin(),nums.begin()+mid);
       vector<int> right(nums.begin()+mid+1,nums.end());
       ret->left=sortedArrayToBST(left);
       ret->right=sortedArrayToBST(right);
       return ret;
    }
};
