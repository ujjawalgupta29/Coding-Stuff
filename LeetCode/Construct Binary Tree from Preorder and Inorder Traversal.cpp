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
    
    unordered_map<int, int> mp;
    int preIdx = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return build(preorder, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int s, int e)
    {
        if(s > e)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        
        if(root == NULL)
            return NULL;
        
        // if(s == e)
        //     return root;
        
        root->left = build(preorder, inorder, s, mp[root->val]-1);
        root->right = build(preorder, inorder, mp[root->val]+1, e);
        
        return root;
    }
};