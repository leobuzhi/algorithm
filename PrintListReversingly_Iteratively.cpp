/*输入一个链表的头结点，从尾到头打印链表每个节点的值。*/


#include<iostream>
#include<stack>
using namespace std;
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};
// void printListReversingly_Iteratively(ListNode* head)
// {
//     stack<ListNode*> nodes;
//     while(head)
//     {
//         nodes.push(head);
//         head=head->m_pNext;
//     }
//     while(!nodes.empty())
//     {
//         cout<<nodes.top()->m_nKey<<endl;
//         nodes.pop();
//     }
// }
void printListReversingly_Iteratively(ListNode* head)
{
    if(head)
    {
        if(head->m_pNext)
        {
            printListReversingly_Iteratively(head->m_pNext);
        }
        cout<<head->m_nKey<<endl;
    }
}
void initList(ListNode* l)
{
    ListNode* p=l;
    int value;
    while(cin>>value)
    {
        ListNode* newNode=new ListNode;
        newNode->m_nKey=value;
        p->m_pNext=newNode;
        p=p->m_pNext;
    }
    p->m_pNext=NULL;
}
int main(int argc, char const *argv[]) {
    /* code */
    ListNode l;
    initList(&l);
    printListReversingly_Iteratively(l.m_pNext);
    cin.get();
    return 0;
}
