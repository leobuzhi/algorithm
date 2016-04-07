#include<iostream>
#include<string>
using namespace std;
void reverse(string &str, int l, int r)
{
    char tmp;
    for (int i = l, j = r; i<j; i++, j--)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
string rightMoveK(string str, int k)
{
    int len = str.length();
    k %= len;            //注意这里
    reverse(str, 0, len - k - 1);
    reverse(str, len - k, len - 1);
    reverse(str, 0, len - 1);
    return str;
}
int main()
{
    string str;
    int k;
    while (cin >> str >> k)
    {
        cout << rightMoveK(str, k) << endl;
    }
    return 0;
}
