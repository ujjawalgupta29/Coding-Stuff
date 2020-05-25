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
    
    TreeNode* build(vector<int>& preorder, int l, int r, int *idx)
    {
        int& root_idx = *idx;
        if(root_idx == preorder.size())
            return NULL;
        
        if(preorder[root_idx] < l || preorder[root_idx] > r)
            return NULL;
        
        int root_val = preorder[root_idx];
        root_idx += 1;
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, l, root_val - 1, idx);
        root->right = build(preorder, root_val + 1, r, idx);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        
        int idx = 0;
        return build(preorder, INT_MIN, INT_MAX, &idx);
    }
};