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
    int max_level = 0;
    vector<int> res;
    
    void rightView(TreeNode* root, int level)
    {
        if(root == NULL)
            return;
        
        if(max_level < level)
        {
            max_level = level;
            res.push_back(root->val);
        }
        
        rightView(root->right, level+1);
        rightView(root->left, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        rightView(root, 1);
        return res;
    }
};