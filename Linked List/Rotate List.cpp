/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;
        
        int len = 1;
        ListNode *curr = head;
        while(curr->next)
        {
            curr=curr->next;
            len++;
        }
        curr->next = head;
        k = k%len;
        while(--len >=k)
        {
            curr = curr->next;
        }
        
        ListNode *first = curr->next;
        curr->next = NULL;
        return first;
        
    }
};
