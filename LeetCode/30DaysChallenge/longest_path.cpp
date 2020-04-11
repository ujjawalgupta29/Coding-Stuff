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
    int max_height = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int height = dfs(root);
        cout << height <<endl;
        return max_height;
    }
    
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(max_height < left + right) max_height = left + right;
        return max(left+1, right+1);
    }
    
};