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
    long sum_nodes = 0;
    long max_mult = INT_MIN;
    int mod = 1e9+7;
    
    void sum(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        sum(root->left);
        sum_nodes += root->val;
        sum(root->right);
    }
    
    long calculate_sum(TreeNode* root)
    {
       if(root == NULL)
           return 0;
        
        long temp_sum = root->val + calculate_sum(root->left) + calculate_sum(root->right);
        
        long temp_mult = ( temp_sum * (sum_nodes - temp_sum) );
        
        max_mult = max(max_mult, temp_mult);
        
        return temp_sum;
    }
    
    int maxProduct(TreeNode* root) {
        sum(root);   
        int temp = calculate_sum(root);
        return max_mult % (int)(mod);
    }
};