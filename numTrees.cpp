/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//my Solution
class Solution {
public:
    int numTrees(int n) {
        if(n==1||n==0)
            return 1;
        int* a=new int[n+1];
        a[0]=a[1]=1;
        int tmp;
        for(int i=2;i<=n;i++)
        {
            tmp=0;
            for(int j=i-1;j>=0;j--)
            {
                tmp+=a[j]*a[i-1-j];
            }
            a[i]=tmp;
        }
        return a[n];
    }
};
