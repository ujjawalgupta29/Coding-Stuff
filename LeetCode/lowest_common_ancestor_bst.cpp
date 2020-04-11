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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p, q);
        return find(root, p, q);
    }
    
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == p || root == q || (p->val < root->val && q->val > root->val) )
            return root;
        if(p->val > root->val && q->val > root->val)
            return find(root->right, p, q);
        else
            return find(root->left, p, q);
    }
};