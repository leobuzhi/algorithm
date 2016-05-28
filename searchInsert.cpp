/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

//my Solution 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        if(size==0)
            return 0;
        int low=0,high=size-1,mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]>target)
                high=mid;
            else if(nums[mid]<target)
                low=mid+1;
            else
                return mid;
        }
        if(nums[low]>=target)
            return low;
        else
            return high+1;
    }
};


//better Solution 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }
};
