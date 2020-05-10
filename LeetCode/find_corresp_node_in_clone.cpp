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
    
    void helper(TreeNode* original, TreeNode* cloned, unordered_map<TreeNode*, TreeNode*> &mp)
    {
        if(original == NULL)
            return;
        
        mp[original] = cloned;
        helper(original->left, cloned->left, mp);
        helper(original->right, cloned->right, mp);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> mp;
        helper(original, cloned, mp);
        return mp[target];
    }
};