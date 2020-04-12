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
    vector<int> in;
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int mini = INT_MAX;
        for(int i=0; i<in.size()-1; i++)
        {
            if(mini > abs(in[i] - in[i+1]))
                mini = abs(in[i] - in[i+1]);
        }
        
        return mini;
    }
    
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
};