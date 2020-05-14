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
    int max_zig = 0;
    unordered_map<TreeNode*, int> left;
    unordered_map<TreeNode*, int> right;
    
    int check(TreeNode* root, int direc, int counts)
    {
        if(root == NULL)
            return 0;
        
        if(direc == 0 && left[root] != 0)
            return left[root];
        
        if(direc == 1 && right[root] != 0)
            return right[root];
        
        if(direc == 0)
        {
            counts = 1 + check(root->left, 1, counts);
            left[root] = counts;
        }
        
        else if(direc == 1)
        {
            counts = 1 + check(root->right, 0, counts);
            right[root] = counts;
        }
        
        return counts;
            
    }
    
    void dfs(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        dfs(root->left);
        int temp = max(check(root, 0, 0), check(root, 1, 0));
        max_zig = max(max_zig, temp);
        dfs(root->right);
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return max_zig-1;
    }
};