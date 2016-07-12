/*Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/






//my Solution
class Solution {
public:
    struct kv{
        int key;
        int value;  
        bool operator <(const kv& k)const
        {
            return key>k.key;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umii;
        for(int x:nums)
            umii[x]++;
        int size=umii.size();
        vector<kv> tmp(size);
        int i=0;
        for(auto x:umii)
        {
            tmp[i].key=x.second;
            tmp[i].value=x.first;
            i++;
        }
        sort(tmp.begin(),tmp.end());
        vector<int> ret;
        for(int i=0;i!=k;i++)
            ret.push_back(tmp[i].value);
        return ret;
    }
};
