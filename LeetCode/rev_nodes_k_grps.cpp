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
    
    vector<ListNode*> reverse(ListNode* head, ListNode* prev, int k)
    {
        if(head == NULL)
            return vector<ListNode*>{prev, head, head};
        
        ListNode* start = head;
        ListNode* curr = head;
        ListNode* ahead = NULL;
        
        while(curr && k--)
        {
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        
        return vector<ListNode*>{prev, curr, start};
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* new_head = NULL;
        ListNode* last;
        
        ListNode* temp2 = head;
        int len = 0;
        while(temp2)
        {
            len++;
            temp2 = temp2->next;
        }
        
        while(temp != NULL)
        {
            if(len < k)
            {
                last->next = temp;
                break;
            }
            vector<ListNode*> ls = reverse(temp, NULL, k);
            prev = ls[0];
            temp = ls[1];
            
            
            if(!new_head)
            {
                new_head = prev;
            }
            else
            {
                last->next = prev;
            }
            
            last = ls[2];
            len = len - k;
        }
        
        return new_head;
    }
};