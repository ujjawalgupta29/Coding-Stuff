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
    int val;
    
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return true;
        val = root->val;
        return values(root);
    }
    
    bool values(TreeNode* root)
    {
        if(root == NULL)
            return true;
        if(root->val != val)
            return false;
        
        return (values(root->left) && values(root->right));
    }
};