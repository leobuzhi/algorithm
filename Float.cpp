#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxN = 100;
long long gcd(long long a, long long b)
{
    long long mi = min(a, b);
    long long ma = max(a, b);
    if (ma%mi == 0)
        return mi;
    return gcd(mi, ma%mi);
}
int main()
{
    char str[maxN];
    long long a, b, c, n, m, nu, de;    //代表整形，小数，循环节,小数的位数，循环节的位数,分子，分母
    a = b = c = 0;
    scanf("%s", str);
    int i,j;    //找到 .和（的位置 
    for (i = 0; i != maxN; i++)
    {
        if (str[i] == '.')
            break;
    }
    for (int k = 0; k != i; k++)
    {
        a = a * 10 + str[k]-'0';
    }
    for (j = i; j != maxN; j++)
    {
        if (str[j] == '(')
            break;
    }
    if (j == maxN)
    {
        c = 0;    //没有循环节
        int k;
        for (k = i + 1; str[k]!='\0'; k++)
            b = b * 10 + str[k] - '0';
        n = k - i - 1;
        m = 0;
    }
    else{
        int k;
        for (k = j + 1; str[k] != ')'; k++)
            c = c * 10 + str[k] - '0';
        m = k - j - 1;
        for (int k = i+1; k != j; k++)
            b = b * 10 + str[k] - '0';
        n = j - i - 1;    
    }
    de = (pow(10, m) - 1)*pow(10, n);
    nu = a*de + b*(pow(10, m) - 1) + c;
    printf("%lld/%lld\n", nu / gcd(de, nu), de / gcd(de, nu));
    return 0;
}
