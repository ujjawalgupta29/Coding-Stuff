/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* merge(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        
        if(t2 == NULL && t1 != NULL)
            return t1;
        
        if(t1 == NULL && t2 != NULL)
        {
            return t2;
        }
        
        t1->val += t2->val;
        t1->left = merge(t1->left, t2->left);
        t1->right = merge(t1->right, t2->right);
        
        return t1;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
};