#include<iostream>
#include<algorithm>
using namespace std;

void reverse(char* str)
{
    char* begin, *end, *ptr;
    begin = end = ptr = str;
    while (*ptr++ != '\0')
    {
        if (*ptr == '\0' || *ptr == ' ')
        {
            end = ptr - 1;
            while (begin<end)
                swap(*begin++,*end--);
            begin = ptr + 1;
        }
    }
    begin = str;
    end = ptr - 2;
    while (begin<end)
        swap(*begin++,*end--);
}
int main()
{
    char str[100]="I am a student";
    reverse(str);
    cout << str << endl;
    return 0;
}
