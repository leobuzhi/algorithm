#include<iostream>
#include<assert.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
    node() :data(0), next(nullptr){}
}node;
typedef node* List;

void initList(List l)
{
    int data;
    List p,q;
    p = l;
    while (cin >> data)
    {
        q = new node;
        q->data = data;
        p->next = q;
        p = q;
    }
}
int kth_element(List l,int k)
{
    assert(l!=nullptr&&k>=1);
    List p, q;
    p = q = l;
    while (k - 1)
    {
        q = q->next;
        k--;
    }
    while (q->next)
    {
        p = p->next;
        q = q->next;
    }
    return p->data;

}
int main()
{
    node l;
    initList(&l);
    node* p = l.next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    node* t = nullptr;
    cout << kth_element(&l, 4) << endl;
    cout << kth_element(&l, 0) << endl;
    cout << kth_element(t, 4) << endl;
    return 0;
}
