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
        ListNode* prev = new ListNode(0);
        ListNode* head = prev;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int sum = getVal(l1) + getVal(l2) + carry;
            head->next = new ListNode(sum%10);
            head = head->next;
            carry = sum/10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        return prev->next;
    }
    
    int getVal(ListNode* l) {
        if(l != NULL)
            return l->val;
        return 0;
    }
};