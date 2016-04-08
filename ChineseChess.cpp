方法一：
#include<iostream>
using namespace std;
int main()
{
    char i = 81;
    while (i--)
    {
        if (i / 9 % 3 != i % 9 % 3)
            cout << i / 9 + 1 << "," << i % 9 + 1 << endl;
    }
    return 0;
}

方法二：
#include<stdio.h>
typedef struct C{
    unsigned char a : 4;
    unsigned char b : 4;
}C;
int main()
{
    C c;
    for (c.a = 1; c.a <= 9; c.a++)
    { 
        for (c.b = 1; c.b <= 9; c.b++)
        {
            if (c.a % 3 != c.b % 3)
                printf("%d,%d \n", c.a, c.b);
        }
    }
    
    return 0;
}
