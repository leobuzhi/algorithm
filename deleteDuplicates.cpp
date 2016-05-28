/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// my Solution 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* fast,*slow,*node;
        slow=head;
        fast=head->next;
        while(fast)
        {
            if(slow->val==fast->val)
            {
                node=fast;
                fast=fast->next;
                slow->next=fast;
                delete node;
            }else
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return head;
    }
};
