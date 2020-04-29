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
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL)
            return res;
        res.push_back(root);
        
        for(int i=0; i<to_delete.size(); i++)
        {
            for(int j = 0; j<res.size(); j++)
            {
                int sz1 = res.size();
                if(res[j]->val == to_delete[i])
                {
                    if(res[j]->left)
                        res.push_back(res[j]->left);
                    if(res[j]->right)
                        res.push_back(res[j]->right);
                    vector<TreeNode*>::iterator it = res.begin() + j;
                    res.erase(it);
                }
                else
                {
                    dfs ( res[j], to_delete[i]);    
                }
                
                if(sz1 != res.size())
                {
                    break;
                }
            }
        }
        
        return res;
    }
    
    void dfs(TreeNode* root, int data)
    {
        if(root == NULL)
            return;
        
        if(root->left)
        {
            if(root->left->val == data)
            {
                if(root->left->left)
                    res.push_back(root->left->left);
                if(root->left->right)
                    res.push_back(root->left->right);
                root->left = NULL;
                return;
            }
            
            else
                dfs(root->left, data);
        }
        
        if(root->right)
        {
            if(root->right->val == data)
            {
                if(root->right->left)
                    res.push_back(root->right->left);
                if(root->right->right)
                    res.push_back(root->right->right);
                root->right = NULL;
                return;
            }
            
            else
                dfs(root->right, data);
        }
    }
};