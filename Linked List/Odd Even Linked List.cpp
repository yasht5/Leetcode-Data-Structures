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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        {
            return head;
        }
        
        int k = head->val;
        
        
        ListNode *odd = NULL;
        ListNode *even = NULL;
        ListNode *res = NULL;
        
        
        ListNode *odd1;
        ListNode *even1;
        int i=1;
        
        ListNode *temp1 = head;
        while(temp1)
        {
            if(i%2)
            {
                if(!odd)
                {
                    odd = new ListNode(temp1->val);
                    odd1 = odd;   
                }
                else
                {
                    odd1->next = new ListNode(temp1->val);
                    odd1 = odd1->next;
                }
            }    
            else
            {
                if(!even)
                {
                    even = new ListNode(temp1->val);
                    even1 = even;
                }
                else
                {   
                    even1->next = new ListNode(temp1->val);
                    even1 = even1->next;
                }
            }
            temp1 = temp1->next;
            i++;
        }
        
        ListNode *p1 = odd;
        ListNode *p2 = even;
        ListNode *temp;
        
        
            while(p1)
            {
                if(!res)
                {
                    res = new ListNode(p1->val);
                    temp = res;
                }
                else
                {
                    temp->next = new ListNode(p1->val);
                    temp = temp->next;
                }
                p1 = p1->next;
            }
            while(p2)
            {
                temp->next = new ListNode(p2->val);
                temp = temp->next;
                p2 = p2->next;
            }
       
       
        return res;   
    }
};
