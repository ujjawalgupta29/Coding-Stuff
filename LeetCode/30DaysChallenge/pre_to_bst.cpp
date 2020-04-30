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
    void build(TreeNode* root, vector<int> &pre, int idx)
    {
        TreeNode* temp = root;
        
        while(temp)
        {
            if(pre[idx] < temp->val)
            {
                if(temp->left)
                    temp = temp->left;
                else
                    break;
            }
            else
            {
                if(temp->right)
                    temp = temp->right;
                else
                    break;
            }
        }
        
        if(temp->val > pre[idx])
        {
            temp->left = new TreeNode(pre[idx]);
        }
        else
        {
            temp->right = new TreeNode(pre[idx]);
        }
    }

    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++)
        {
            build(root, preorder, i);
        }
        return root;
    }
};