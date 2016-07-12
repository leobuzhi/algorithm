/*Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.*/










//my first Solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0)
            return vector<int>();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        auto first1=nums1.begin(),first2=nums2.begin(),last1=nums1.end(),last2=nums2.end();
        vector<int> ret;
        while(first1!=last1&&first2!=last2)
        {
            if(*first1<*first2)
                first1++;
            else if(*first2<*first1)
                first2++;
            else
            {
                ret.push_back(*first1);
                first1++;
                first2++;
            }
        }
        set<int> tmp(ret.begin(),ret.end());
        return vector<int>(tmp.begin(),tmp.end());
    }
};


//my second Solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umii1,umii2;
        for(int x:nums1)
            umii1[x]=1;
        vector<int> ret;
        for(int x:nums2)
            if(umii1[x]==1)
                umii2[x]=1;
        for(auto x:umii2)
            if(x.second==1)
                ret.push_back(x.first);
        return ret;
    }
};

