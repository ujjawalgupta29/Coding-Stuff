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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* ptr1, *ptr2, *temp;
        ptr1 = head;
        ptr2 = head->next;
        temp = ptr2;
        
        while(ptr1->next && ptr2->next && ptr1->next->next )
        {
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            ptr2->next = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr1->next = temp;
        
        return head;
        
    }
};