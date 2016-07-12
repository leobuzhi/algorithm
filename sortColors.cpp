/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.*/




//my Solution 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3]={0,0,0};
        for(int x:nums)
            a[x]++;
        int k=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<a[i];j++)
                nums[k++]=i;
    }
};

//another Solution
class Solution {
public:
    void sortColors(int A[], int n) {
        int second = n - 1, zero = 0;
        for (int i = 0; i <= second; i++) {
            while (A[i] == 2 && i<second) swap(A[i], A[second--]);
            while (A[i] == 0 && i>zero) swap(A[i], A[zero++]);
        }
    }
};
