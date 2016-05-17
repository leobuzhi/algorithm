/*
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return abs(log10(n)/log10(3)-(int)(log10(n)/log10(3)))<0.0000000001;
    }
};
