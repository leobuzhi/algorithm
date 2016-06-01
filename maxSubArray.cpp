/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

//my Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxSum=0x80000000;
        int len=nums.size();
        for(int i=0;i!=len;i++)
        {
            if(sum<0)
                sum=nums[i];
            else
                sum+=nums[i];
            if(maxSum<sum)
                maxSum=sum;
        }
        return maxSum;
    }
};
