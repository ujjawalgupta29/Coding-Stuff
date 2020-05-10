// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int depth(TreeNode* root)
//     {
//         if(!root)
//             return 0;
//         return max(depth(root->left), depth(root->right)) + 1;
//     }
    
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL)
//             return true;
        
//         return isBalanced(root->left) && isBalanced(root->right) && 
//             abs(depth(root->left) - depth(root->right)) <= 1;
//     }
// };

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
    int check(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int left = check(root->left);
        if(left == -1)
            return -1;
        
        int right = check(root->right);
        if(right == -1)
            return -1;
        
        if(abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        int res = check(root);
        return (res == -1) ? 0 : 1;
    }
};