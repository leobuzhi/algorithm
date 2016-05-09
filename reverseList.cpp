/*Reverse a singly linked list.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* reverseHead=nullptr;
        ListNode* node=head;
        ListNode* pre=nullptr;
        while(node)
        {
            ListNode* pnext=node->next;
            if(pnext==nullptr)
                reverseHead=node;
            node->next=pre;
            pre=node;
            node=pnext;
        }
        return reverseHead;
    }
};
