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
    
    int postIdx;
    unordered_map<int, int> mp;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;
        
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        
        return buildTree(postorder, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int s, int e)
    {
        if(s > e)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        
        root->right = buildTree(postorder, inorder, mp[root->val] + 1, e);
        root->left = buildTree(postorder, inorder, s, mp[root->val] - 1);
        
        return root;
    }
};