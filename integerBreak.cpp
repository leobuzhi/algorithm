/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.
 Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: you may assume that n is not less than 2.
*/


//my Solution
class Solution {
public:
    int integerBreak(int n) {
        int *a;
        if(n<=6)
            a=new int[7];
        else
            a=new int[n+1];
        a[2]=1;
        a[3]=2;
        a[4]=4;
        a[5]=6;
        a[6]=9;
        for(int i=7;i<=n;i++)
            a[i]=3*a[i-3];
        return a[n];
    }
};
