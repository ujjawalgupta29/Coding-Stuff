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
    
    vector<vector<int>> res;
    
    void cal_sum(TreeNode* root, int pre, int sum, vector<int> temp)
    {
        if(!root)
        {
            return;
        }
        
        pre += root->val;
        temp.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL)
        {
            if(pre == sum)
            {
                res.push_back(temp);
            }
        }
        
        cal_sum(root->left, pre, sum, temp);
        cal_sum(root->right, pre, sum, temp);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        cal_sum(root, 0, sum, temp);
        return res;
    }
};