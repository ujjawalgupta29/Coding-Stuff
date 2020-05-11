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
    
    int path(TreeNode* root, int &len)
    {
        if(root == NULL)
            return 0;
        
        int l = path(root->left, len);
        int r = path(root->right, len);
        
        l = (root->left && root->val == root->left->val) ? l+1 : 0;
        r = (root->right && root->val == root->right->val) ? r+1 : 0;
        len = max(len, l+r);
        return max(l,r);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int len = 0;
        path(root, len);
        return len;
    }
};