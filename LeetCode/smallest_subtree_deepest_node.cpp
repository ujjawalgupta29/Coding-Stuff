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
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || root == p || root == q) return root;
        
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        
        if(left && right)   return root;
        if(!left && !right) return NULL;
        
        return !left ? right : left;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root || ( !root->left && !root->right) )
            return root;
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                if(i == 0) left = temp;
                if(i == sz-1) right = temp;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        return lca(root, left, right);
    }
};