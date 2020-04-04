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
    ListNode *detectCycle(ListNode *head) {
        ListNode* first, *second;
        
        if(!head || !head->next || !head->next->next)
            return NULL;
        
        first = head->next;
        second = head->next->next;
        
        while(first != second)
        {
            if(first->next)
                first = first->next;
            else
                return NULL;
            if(second->next && second->next->next)
                second = second->next->next;
            else
                return NULL;
        }
        
        first = head;
        
        while(first != second)
        {
            first = first->next;
            second = second->next;
        }
        
        return first;
    }
};