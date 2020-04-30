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
    void traverse(TreeNode* root, vector<int> &nums)
    {
        if(!root)
            return;
        traverse(root->left, nums);
        nums.push_back(root->val);
        traverse(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        if(root == NULL)
            return 0;
        traverse(root, nums);
        
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int sum = nums[l] + nums[r];
            if(sum == k)
                return true;
            else if(sum < k)
                l++;
            else
                r--;
        }
        
        return 0;
    }
};