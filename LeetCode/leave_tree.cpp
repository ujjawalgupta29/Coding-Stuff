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
    vector<int> tree1;
    vector<int> tree2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leaves(root1, tree1);
        leaves(root2, tree2);
        
        int n1 = tree1.size();
        int n2 = tree2.size();
        
        if(n1 != n2)
            return false;
        
        for(int i=0; i<n1; i++)
        {
            if(tree1[i] != tree2[i])
                return false;
        }
        
        return true;
    }
    
    void leaves(TreeNode* root, vector<int> &tree)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            tree.push_back(root->val);
        
        leaves(root->left, tree);
        leaves(root->right, tree);
    }
};