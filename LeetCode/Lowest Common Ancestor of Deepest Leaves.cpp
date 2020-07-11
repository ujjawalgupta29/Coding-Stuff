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

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int ht = 0;
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        height(root, 0);
        return findLCA(root, ht, 0);
    }
    
    void height(TreeNode* root, int curr_ht)
    {
        if(root == NULL)
            return;
        
        ht = max(ht, curr_ht);
        height(root->left, curr_ht + 1);
        height(root->right, curr_ht + 1);
    }
        
    
    TreeNode* findLCA(TreeNode* root, int ht, int curr_ht)
    {
        if(root == NULL || curr_ht == ht)
            return root;
        
        TreeNode* left = findLCA(root->left, ht, curr_ht+1);
        TreeNode* right = findLCA(root->right, ht, curr_ht+1);
        
        if(left && right)
            return root;
        
        else
            return (left) ? left : right;
    }
};