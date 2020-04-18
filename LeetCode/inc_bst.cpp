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
    TreeNode* newroot, *curr;
    TreeNode* increasingBST(TreeNode* root) {
        
        create(root);
        
        return newroot;
    }
    
    void create(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        create(root->left);
        if (newroot == NULL) 
        { 
            newroot = new TreeNode(root->val);
            curr = newroot;
        }
        else 
        {
            curr->right = new TreeNode(root->val);
            curr=curr->right;
        }
        create(root->right);
    }
};