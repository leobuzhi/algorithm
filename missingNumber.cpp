/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?*/

//my Solution 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unordered_map<int,int> umii;
       int n=nums.size();
       for(int i=0;i!=n;i++)
            umii[nums[i]]++;
       for(int i=0;i!=n+1;i++)
            if(!umii[i])
                return i;
    }
};


//better Solution 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int result=size;
        for(int i=0;i!=size;i++)
            result=result^nums[i]^i;
        return result;
    }
};
