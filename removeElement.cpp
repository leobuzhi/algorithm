/*
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example:
Given input array nums = [3,2,2,3], val = 3
Your function should return length = 2, with the first two elements of nums being 2.
*/

//my Solution 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        int i=0,j=len-1,cnt=0;
        while(i<=j)
        {
            if(nums[i]==val)
            {
                if(nums[j]==val)
                {
                    j--;
                }else
                {
                    swap(nums[i],nums[j]);
                    i++;
                    j--;
                }
                cnt++;
            }else{
                i++;
            }
        }
        nums.resize(len-cnt);
        return len-cnt;
    }
};

//better Solution 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        int begin=0;
        for(int i=0;i!=len;i++)
            if(nums[i]!=val)
                nums[begin++]=nums[i];
        return begin;
    }
};
