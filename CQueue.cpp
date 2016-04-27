/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成在队列尾部插入节点和在队列头部删除节点的功能。
template<typename T>
class CQueue{
public:
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
*/

#include<iostream>
#include<stack>
using namespace std;
template<typename T>
class CQueue{
public:
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
    if (stack1.empty())
    {
        stack1.push(node);
    }
    else{
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
}
template<typename T>
T CQueue<T>::deleteHead()
{
    T ret = stack1.top();
    stack1.pop();
    return ret;
}
int main(int argc, char const *argv[]) {
    CQueue<int> cqi;
    cqi.appendTail(1);
    cqi.appendTail(2);
    cqi.appendTail(3);
    cout << cqi.deleteHead() << endl;
    cout << cqi.deleteHead() << endl;
    cout << cqi.deleteHead() << endl;
    cin.get();
    return 0;
}
