/*Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

//my Solution 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umii;
        for(int x:nums)
            umii[x]++;
        for(auto x:umii)
            if(x.second==1)
                return x.first;
    }
};



//better Solution 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
    return ones;
    }
};
