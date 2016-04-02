#include<iostream>
#include<algorithm>
using namespace std;
bool nim(int x, int y)
{
    double a, b;
    a = (1 + sqrt(5.0)) / 2;
    b = (3 + sqrt(5.0)) / 2;
    if (x == y)
        return true;
    if (x > y)
        swap(x, y);
    return (x != (long)floor((y - x)*a));
}
int main()
{
    cout << nim(1, 2) << endl;        //0
    cout << nim(3, 5) << endl;        //0
    cout << nim(4, 7) << endl;        //0
    cout << nim(6, 10) << endl;        //0
    cout << nim(8, 13) << endl;        //0
    cout << nim(2, 10) << endl;        //1
    cout << nim(3, 7) << endl;        //1
    cout << nim(13, 8) << endl;        //0
    return 0;
}
