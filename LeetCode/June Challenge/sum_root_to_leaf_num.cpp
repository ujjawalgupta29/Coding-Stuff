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
    int res = 0;
    
    void dfs(TreeNode* root, int num) {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL) {
            num = num*10 + root->val;
            res += num;
            return;
        }
        
        num = num*10 + root->val;
        dfs(root->left, num);
        dfs(root->right, num);
    }
    
    int sumNumbers(TreeNode* root) {
        int num = 0;
        dfs(root, num); 
        return res;
    }
};