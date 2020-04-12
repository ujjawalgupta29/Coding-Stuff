/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        bool first=0, second=0;
        queue<TreeNode*> q;
        q.push(root);
        int parent1 = -1, parent2 = -1;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left)
                {
                    q.push(temp->left);
                    if(temp->left->val == x)
                    {
                        first = 1;
                        parent1 = i;
                    }
                    if(temp->left->val == y)
                    {
                        second = 1;
                        parent2 = i;
                    }
                }
                
                if(temp->right)
                {
                    q.push(temp->right);
                    if(temp->right->val == x)
                    {
                        first = 1;
                        parent1 = i;
                    }
                    if(temp->right->val == y)
                    {
                        second = 1;
                        parent2 = i;
                    }
                }
            }
            if(first && second && (parent1 != parent2))
                return true;
            if(first && second)
                return false;
            if(first || second)
                return false;
        }
        
        return false;
    }
};