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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* ptr = temp;
        
        while(ptr->next)
        {
            if(ptr->next->val == val)
            {
                ptr->next = ptr->next->next;
            }
            if(ptr->next && ptr->next->val != val)
                ptr = ptr->next;
        }
        
        return temp->next;
    }
};  