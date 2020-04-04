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
    bool hasCycle(ListNode *head) {
        ListNode* first, *second;
        
        if(!head || !head->next || !head->next->next)
            return 0;
        
        first = head->next;
        second = head->next->next;
        
        while(first && second)
        {
            if(first == second)
                return 1;
            
            if(first->next)
                first = first->next;
            else
                break;
            if(second->next && second->next->next)
                second = second->next->next;
            else
                break;
        }
        
        return 0;
    }
};