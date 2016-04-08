//两堆石头，玩家根据如下规则轮流取石头：
//每人每次可以从两堆石头中各取出数量相等的石头，或者仅从一堆石头中取出任意数量的石头；
//最后把剩下的石头一次拿光的人获胜
//定义一个函数如下：
//bool nim(n，m)
//要求返回一个布尔值，表明首先取石头的玩家是否能够赢得这个游戏。
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
