/*请实现一个函数，把字符串中的每个空格替换成“%20”，例如输入“I am ok”，，则输出“I%20am%20ok”。*/



#include<iostream>
#include<string>
using namespace std;
char* replaceBlacnk(char * str,int len)
{
    if(str==NULL||len<=0)
        return NULL;
    int blackCnt=0;
    for(int i=0;i!=len;i++)
    {
        if(str[i]==' ')
            blackCnt++;
    }
    int newLen=len+2*blackCnt;
    char* newStr=new char[newLen];
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]!=' ')
        {
            newStr[--newLen]=str[--len];
        }else{
            newStr[--newLen]='0';
            newStr[--newLen]='2';
            newStr[--newLen]='%';
            len--;
        }
    }
    return newStr;
}
int main(int argc, char const *argv[]) 
{
    char* str1="I am ok";
    char* str2="how you doing?";
    cout<<replaceBlacnk(str1,7)<<endl;
    cout<<replaceBlacnk(str2,14)<<endl;
    return 0;
}
