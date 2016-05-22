/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/


//my Solution 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size;
        do
        {
            size=nums.size();
            auto it=unique(nums.begin(),nums.end());
            nums.resize(distance(nums.begin(),it));
        }while(size!=nums.size());
        return nums.size();
    }
};



//better Solution 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        if(size<2)
            return size;
        int id=1;
        for(int i=1;i!=size;i++)
            if(nums[i]!=nums[i-1])
                nums[id++]=nums[i];
        return id;
    }
};



//better Solution 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int cnt=0;
        for(int i=1;i<size;i++)
        {
            if(nums[i]==nums[i-1])
                cnt++;
            else
                nums[i-cnt]=nums[i];
        }
        return size-cnt;
    }
};
