#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void* Memcpy(void* dst, const void* src, size_t size);
 
int main(int argc, char* argv[])
{
    char buf[100] = "abcdefghijk";
    //memcpy(buf+2, buf, 5);
    Memcpy(buf+2, buf, 5);
    printf("%s\n", buf+2);
}
 
void* Memcpy(void* dst, const void* src, size_t size)
{
    char* psrc;
    char* pdst;
 
    if(NULL == dst || NULL == src)
    {
        return NULL;
    }
 
    if((src < dst) && (char*)src + size > (char*)dst) // 自后向前拷贝
    {
        psrc = (char*)src + size - 1;
        pdst = (char*)dst + size - 1;
        while(size--)
        {
            *pdst-- = *psrc--;
        }
    }
    else
    {
        psrc = (char*)src;
        pdst = (char*)dst;
        while(size--)
        {
            *pdst++ = *psrc++;
        }
    }
 
    return dst;
}
