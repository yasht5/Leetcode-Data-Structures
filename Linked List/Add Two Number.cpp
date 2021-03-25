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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        if(!l1 && !l2 && carry==0)
        {
            return NULL;
        }
        
        int val = l1->val + l2->val;
        carry = val/10;
        ListNode *res = new ListNode(val%10);
        ListNode *temp = res;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2)
        {
            val = 0;
            if(l1==NULL)
            {
                val=l2->val+carry;
            }
            else if(l2==NULL)
            {
                val=l1->val+carry;
            }
            else
            {
                val=l1->val + l2->val + carry;
            
            }
            carry = val/10;
            temp->next = new ListNode(val%10);
            temp = temp->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            
        }
        
        if(carry)
        {
            temp->next = new ListNode(carry);
        }
        return res;
    }
};
