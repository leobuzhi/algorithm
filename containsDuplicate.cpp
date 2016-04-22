/*Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
Subscribe to see which companies asked this question*/

//my Solution 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umii;
        for(auto& x:nums)
            umii[x]++;
        for(auto x:umii)
            if(x.second>1)
                return true;
        return false;
    }
};



//better Solution 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    return nums.size() > set<int>(nums.begin(), nums.end()).size(); 
    }
};
