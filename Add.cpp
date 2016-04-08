#include<iostream>
using namespace std;
int add(int a, int b)
{
    int sum = 0, tmp = 0;
    do{
        sum = a^b;
        tmp = a&b;
        b = tmp << 1;
        a = sum;
    } while (tmp);
    return sum;
}
int main()
{
    cout << add(1, 3) << endl;
    cout << add(5, 8) << endl;
    cout << add(-2, 15) << endl;
    cout << add(-4, -7) << endl;
    
    return 0;
}
