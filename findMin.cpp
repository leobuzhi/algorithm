/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.*/

class Solution {
public:
    int findMin(vector<int>& nums) {
       int left=0,right=nums.size()-1,mid;
       if (nums[0]<nums[right])
            return nums[0];
       while (left<right)
       {
            mid = left + (right - left) / 2;
            if (nums[left]<nums[mid])
            {
                left = mid;
            }
            else if (nums[right]>nums[mid])
            {
                right = mid;
            }
            else
            {
                return nums[right];
            }
        }
        return nums[left];
    }
};


//if there exists duplicate in the array
//#include<iostream>
//#include<assert.h>
//using namespace std;
//int specialMin(int* nums,int length)
//{
//	int ret = nums[0];
//	for (int i = 1; i != length; i++)
//	{
//		if (nums[i] < ret)
//			ret = nums[i];
//	}
//	return ret;
//}
//int min(int* nums, int length)
//{
//	assert(nums != NULL&&length >= 1);
//	if (nums[0]<nums[length - 1])
//		return nums[0];
//	int left = 0, right = length - 1;
//	int mid = left + (right - left) / 2;
//	if (nums[left] == nums[mid] && nums[mid] == nums[right])
//		return specialMin(nums,length);
//	while (left<right)
//	{
//		int mid = left + (right - left) / 2;
//		if (nums[left]<nums[mid])
//		{
//			left = mid;
//		}
//		else if (nums[right]>nums[mid])
//		{
//			right = mid;
//		}
//		else
//		{
//			return nums[right];
//		}
//	}
//	return nums[left];
//}

