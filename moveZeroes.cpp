/*Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations. */


//my Solution 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)
            return ;
        int i=0,j=0;
        for(;j!=nums.size();j++)
        {
            if(nums[j]!=0)
                nums[i++]=nums[j];
        }
        for(;i!=nums.size();i++)
        {
            nums[i]=0;
        }
    }
};



//better Solution 
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int last = 0, cur = 0;
    while(cur < nums.size()) {
        if(nums[cur] != 0) {
            swap(nums[last], nums[cur]);
            last++;
        }
        cur++;
    }
}
};
