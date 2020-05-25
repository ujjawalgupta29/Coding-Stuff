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
    
    int counts = 0;
    
    void count_nodes(TreeNode* root, int data)
    {
        if(root == NULL)
            return;
        
        if(root->val >= data)
            counts++;
        
        count_nodes(root->left, max(root->val, data));
        count_nodes(root->right, max(root->val, data));
        
        
    }
    
    int goodNodes(TreeNode* root) {
        count_nodes(root, root->val);
        return counts;
    }
};