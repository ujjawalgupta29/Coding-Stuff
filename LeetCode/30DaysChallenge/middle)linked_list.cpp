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
    ListNode* middleNode(ListNode* head) {
        ListNode*slow, *fast;
        slow = head;
        fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                break;
        }
        
        return slow;
    }
};