#include<iostream>
#include<assert.h>
using namespace std;
int tag = 1;
int atoi(const char* str)
{
    long long ret = 0;
    int sign = 1;
    assert(str != nullptr);
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = 0;
        str++;
    }
    while (*str != '\0')
    {
        int flag = sign ? 1 : -1;
        if (*str>'9' || *str<'0')
        {
            tag = 0;
            return 0;
        }
        ret = ret * 10 + flag*(*str - '0');
        if ((sign&&ret > 0x7fffffff)||(!sign&&ret<(signed int)0x80000000))
        {
            tag = 0;
            return 0;
        }
        str++;
    }
    return ret;
}

int main()
{
    char *str1 = "123";
    int ret = 0;
    ret = atoi(str1);
    if (!ret)
    {
        if (!tag)
        {
            cout << "error" << endl;
            tag = 1;
        }
        else{
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ret << endl;
    }

    char *str2 = "-123";
    ret = atoi(str2);
    if (!ret)
    {
        if (!tag)
        {
            cout << "error" << endl;
            tag = 1;
        }
        else{
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ret << endl;
    }
    char *str3 = "0";
    ret = atoi(str3);
    if (!ret)
    {
        if (!tag)
        {
            cout << "error" << endl;
            tag = 1;
        }
        else{
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ret << endl;
    }
    char *str4 = "1b3";
    ret = atoi(str4);
    if (!ret)
    {
        if (!tag)
        {
            cout << "error" << endl;
            tag = 1;
        }
        else{
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ret << endl;
    }

    char *str5 = "9999999999999999999999999999999999";
    ret = atoi(str5);
    if (!ret)
    {
        if (!tag)
        {
            cout << "error" << endl;
            tag = 1;
        }
        else{
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ret << endl;
    }
    char *str6 = "-9999999999999999999999999999999999";
    ret = atoi(str6);
    if (!ret)
    {
        if (!tag)
        {
            cout << "error" << endl;
            tag = 1;
        }
        else{
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ret << endl;
    }
    return 0;
}
