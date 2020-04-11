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
    int height = 0;
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        find_height(root, 0);
        vector<vector<int>> res(height);
        if(height == 0)
            return res;
        
        // cout << height << endl;
        level_order(root, res, height - 1);
        return res;
    }
    
    void level_order(TreeNode* root, vector<vector<int>> &res, int level)
    {
        if(root == NULL)
            return;
        
        level_order(root->left, res, level - 1);
        res[level].push_back(root->val);
        level_order(root->right, res, level - 1);
    }
    
    void find_height(TreeNode* root, int level)
    {
        if(root == NULL)
        {
            height = max(height, level);
            return;
        }
        find_height(root->left, level+1);
        find_height(root->right, level+1);
    }
};