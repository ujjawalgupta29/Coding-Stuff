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
    bool isValidBST(TreeNode* root, TreeNode* l = NULL, TreeNode* r = NULL) {
        if(root == NULL)
            return true;

        if(l != NULL && root->val <= l->val)
            return false;
        
        if(r != NULL && root->val >= r->val)
            return false;
        
        return isValidBST(root->left, l, root ) && 
            isValidBST(root->right, root, r);
    }
};