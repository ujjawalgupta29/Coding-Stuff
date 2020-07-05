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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        
        while(lists.size() > 1)
        {
            lists.push_back(MergeTwoList(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return lists[0];
    }
    
    ListNode* MergeTwoList(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = MergeTwoList(l1->next, l2);
            return l1;
        }
        
        else
        {
            l2->next = MergeTwoList(l1, l2->next);
            return l2;
        }
    }
};