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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        
        int i = 0;
        return dfs(root, i, arr);
        
    }
    
    bool dfs(TreeNode* root, int i, vector<int>& arr)
    {
        if( i >= arr.size())
            return false;
        
        if(root == NULL)
        {
            return arr.size() == 0;
        }
        
        if ((root->left == NULL && root->right == NULL) && 
       (root->val == arr[i]) && (i == arr.size() - 1)) 
            return true; 
  
        
        if(i >= arr.size() || root->val != arr[i])
        {
            return false;
        }
        
        return ( dfs(root->left, i+1, arr) || dfs(root->right, i+1, arr) ); 
        
    }
};