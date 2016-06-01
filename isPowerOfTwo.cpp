/*
Given an integer, write a function to determine if it is a power of two.
*/

//my Solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
        return n?(n&(n-1))==0:n;
    }
};


//better Solution 
class Solution {
public:
    bool isPowerOfTwo(int n) {
       return (n>0&&((n&(n-1))==0));
    }
};
