/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* dfs(Node* head)
    {
        if(!head)
            return NULL;
        
        if(head->child != NULL)
        {
            Node* prev = head->next;
            head->child->prev = head;
            head->next = dfs(head->child);
            head->child = NULL;
            Node* temp = head;
            // cout << temp->val << " " << prev->val << endl;
            while(temp->next)
                temp = temp->next;
            if(prev)
                prev->prev = temp;
            temp->next = prev;
        }
        
        head->next = dfs(head->next);
        
        return head;
    }
    
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        return dfs(head);
    }
};