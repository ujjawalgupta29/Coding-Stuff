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
    int maxele = INT_MIN;

    int maxPathSum(TreeNode* root) {
        
        vector<int> res = maxSum(root);
        // cout<<maxele<<endl;
        return (maxele < 0 ) ? maxele : res[1];
    }
    
    vector<int> maxSum(TreeNode* root)
    {
        if(root == NULL)
        {
            return vector<int>{0, 0};    
        }
        
        if(root->val > maxele)
        {
            maxele = root->val;
        }
        
        vector<int> left = maxSum(root->left);
        vector<int> right = maxSum(root->right);
        
        int leftBranchSum = left[0], leftSum = left[1];
        int rightBranchSum = right[0], rightSum = right[1];
        
        int maxChildBranchSum = max(leftBranchSum, rightBranchSum);
        
        int maxBranchSum = max(maxChildBranchSum + root->val, root->val);
        int maxTreeSum = max(maxBranchSum, leftBranchSum + root->val + rightBranchSum);
        
        int maxPathSum = (leftSum >= rightSum) ? max(leftSum, maxTreeSum) : max(rightSum, maxTreeSum);
        
        return vector<int>{maxBranchSum, maxPathSum};
    }
};