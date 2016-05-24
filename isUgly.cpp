/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.
*/
















class Solution {
public:
    bool isUgly(int num) {
    for (int x : {2, 3, 5})
        while (num&&num%x == 0)
            num /= x;
    return num == 1;
    }
};
