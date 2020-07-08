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
        string s1, s2;
        
        while(l1)
        {
            s1 += to_string(l1->val);
            l1 = l1->next;
        }
        
        while(l2)
        {
            s2 += to_string(l2->val);
            l2 = l2->next;
        }
        
        int len1 = s1.size() - 1;
        int len2 = s2.size() - 1;
        int carry = 0;
        ListNode* result = NULL;
        // cout << s1 << " " << s2 << endl;
        // cout << " len 1 = " << len1 << " len2 = " << len2 << endl;
        
        while(len1 >= 0 || len2 >= 0 || carry)
        {
            // cout << len1 << " " << len2 << " " << carry << endl;
            int x = (len1 >= 0) ? (s1[len1--] - '0') : 0;
            int y = (len2 >= 0) ? (s2[len2--] - '0') : 0;
            int sum = x + y + carry;
            carry = sum/10;
            int val = sum%10;
            
            result = add(result, val);
            
        }
              
        return result;
    }
              
    ListNode* add(ListNode* result, int val) 
    {
        if(result == NULL)
        {
            result = new ListNode(val);
            return result;
        }
        
        ListNode* curr = result;
        ListNode* temp = new ListNode(val);
        result = temp;
        temp->next = curr;
        return result;
    }
              
              
};