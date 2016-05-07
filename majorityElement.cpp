/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
Subscribe to see which companies asked this question*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int time=0,ret;
        for(auto& x:nums)
        {
            if(!time)
            {
                time++;
                ret=x;
            }
            else{
                if(ret==x)        
                    time++;
                else
                    time--;
            }
        }
        return ret;
    }
};
