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
    string s;
    string tree2str(TreeNode* t) {
        generate(t);
        return s;
    }
    
    void generate(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        s += to_string(root->val);
        if(root->left)
        {
            s += '(';
            generate(root->left);
            s += ')';
        }
        else if(root->right)
            s += "()";
            
        if(root->right)
        {
            s += '(';
            generate(root->right);
            s += ')';
        }
    }
};