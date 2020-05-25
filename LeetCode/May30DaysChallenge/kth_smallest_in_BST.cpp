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
    int kthSmallest(TreeNode* root, int k) {

        vector<int> v;
        
        inorder(root, v, k);
        
        return v[k-1];
    }
    
    void inorder(TreeNode* root, vector<int> &v, int k)
    {
        if(root == NULL || v.size() >= k)
            return;
        
        inorder(root->left, v, k);
        
        v.push_back(root->val);
        
        inorder(root->right, v, k);
    }
};