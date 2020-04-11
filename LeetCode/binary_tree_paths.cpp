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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return res;
        generate_paths(root, "");
        return res;
    }
    
    void generate_paths(TreeNode* root, string s)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            if(s.length() != 0)
                s += "->";
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        
        if(s.length() != 0)
            s += "->";
        s += to_string(root->val);
        generate_paths(root->left, s);
        generate_paths(root->right, s);
    }
};