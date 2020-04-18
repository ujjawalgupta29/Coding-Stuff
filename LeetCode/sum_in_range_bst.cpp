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
    int sum = 0;
    int left;
    int right;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return 0;
        left = L;
        right = R;
        
        calculate(root);
        return sum;
    }
    
    void calculate(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        if(root->val >= left && root->val <= right)
            sum += root->val;
        
        if(root->val > left)
            calculate(root->left);
        
        if(root->val < right)
            calculate(root->right);
    }
};