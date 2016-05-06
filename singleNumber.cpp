/*Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

//my Solution 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp=0;
        for(auto x:nums)
            tmp^=x;
            return tmp;
    }
};
