static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> s1, s2;
        
        while(l1)
        {
            s1.push_back(l1->val);
            l1 = l1->next;
        }
        
        while(l2)
        {
            s2.push_back(l2->val);
            l2 = l2->next;
        }
        
        int len1 = s1.size() - 1;
        int len2 = s2.size() - 1;
        int carry = 0;
        ListNode* result = NULL;
        
        while(len1 >= 0 || len2 >= 0 || carry)
        {
            int x = (len1 >= 0) ? (s1[len1--]) : 0;
            int y = (len2 >= 0) ? (s2[len2--]) : 0;
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