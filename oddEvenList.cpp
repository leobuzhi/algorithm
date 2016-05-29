/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//my Solution
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr||head->next==nullptr||head->next->next==nullptr)
        return head;
    ListNode* firstHead,*secondHead,*firstNode,*secondNode,*node;
    firstNode=firstHead=head;
    secondNode=secondHead=head->next;
    node=secondNode->next;
    int k=1;
    while(node!=nullptr)
    {
        if(k%2==1)
        {
            firstNode->next=node;
            firstNode=node;
        }
        else
        {
            secondNode->next=node;
            secondNode=node;
        }
        node=node->next;
        k++;
    }
    if(k%2==0)
    {
        secondNode->next=nullptr;
    }
    firstNode->next=secondHead;
    return firstHead;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//better Solution
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
