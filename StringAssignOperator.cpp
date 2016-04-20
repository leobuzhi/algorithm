#include<iostream>
using namespace std;

class CMyString{
public:
    CMyString(const char * pdata = nullptr);
    CMyString(const CMyString & str);
    CMyString& CMyString::operator =(const CMyString& str);
    ~CMyString(){
        delete[] m_pData;
    }
private:
    char *m_pData;
};
CMyString::CMyString(const char * str)
{
    if (str == nullptr)
    {
        m_pData = new char[1];
        m_pData = '\0';
    }
    else{
        m_pData = new char[strlen(str) + 1];
        strcpy(m_pData, str);
    }
}
CMyString::CMyString(const CMyString & str)
{
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}
//CMyString& CMyString::operator =(const CMyString& str)    //一般方法
//{
//    if (&str == this)
//        return *this;
//    delete m_pData;
//    m_pData = nullptr;
//    m_pData = new char[strlen(str.m_pData) + 1];
//    char * tmp = m_pData;
//    strcpy(m_pData, str.m_pData);mp
//    return *this;
//}
CMyString& CMyString::operator=(const CMyString& str)    //高级方法
{
    if (&str != this)
    {
        CMyString tmp(str);
        char * s = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = s;
    }
    return *this;
}

int main()
{
    char * a = "abc";
    CMyString str1(a);
    CMyString str2 = str1;
    return 0;
}
