/*
Given an array of integers and an integer k, find out whether there are two distinct
indices i and j in the array such that nums[i] = nums[j] and the difference between i and jis at most k.
*/

//my Solution
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mii;
        vector<int> vi,anoVi;
        for(auto x:nums)
            mii[x]++;
        for(auto x:mii)
        {
            if(x.second>1)
            {
                vi.clear();
                anoVi.clear();
                for(int i=0;i!=nums.size();i++)
                {
                    if(x.first==nums[i])
                        vi.push_back(i);
                }
                for(auto it=vi.begin();it!=vi.end()-1;it++)
                    anoVi.push_back(*(it+1)-(*it));
                sort(anoVi.begin(),anoVi.end());
                if(anoVi[0]<=k)
                    return true;
            }
        }
        return false;
    }
};



//another
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;

       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;

       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }

       return false;
    }
};
