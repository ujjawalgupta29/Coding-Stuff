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
    int paths = 0;
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        paths += sum_from_root(root, 0, sum);
        
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        
        return paths;
    }
    
    int sum_from_root(TreeNode* root, int pre, int sum)
    {
        if(root == NULL)
            return 0;
        
        int curr = pre + root->val;
        
        return (curr == sum) + sum_from_root(root->left, curr, sum) + 
            sum_from_root(root->right, curr, sum);
    }
};