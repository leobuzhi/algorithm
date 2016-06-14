/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode* head;
        if(l1->val<=l2->val)
        {
            head=l1;
            head->next=mergeTwoLists(l1->next,l2);
        }else
        {
            head=l2;
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};
