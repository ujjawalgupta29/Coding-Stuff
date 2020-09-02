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
    
    pair<TreeNode*, TreeNode*> find(TreeNode* root, int key, TreeNode* parent)
    {
        if(root == NULL)
            return {parent, NULL};
        
        if(root->val == key)
            return {parent, root};
        
        if(root->val < key)
            return find(root->right, key, root);
        
        else 
            return find(root->left, key, root);
    }
    
    TreeNode* nodeDeletion(TreeNode* node)
    {
        if(node == NULL)
            return NULL;
        
        if(node->right == NULL)
            return node->left;
        
        if(node->left == NULL)
            return node->right;
        
        TreeNode* next = node->right;
        
        TreeNode* pre = NULL;
        
        for(; next->left != NULL; pre = next, next = next->left);
        next->left = node->left;
        if(node->right != next) {
            pre->left = next->right;
            next->right = node->right;
        }
        return next;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*,TreeNode*> to_delete_pair = find(root, key, NULL);
        
        TreeNode* to_delete_parent = to_delete_pair.first;
        TreeNode* to_delete_node = to_delete_pair.second;
        
        if(to_delete_parent == NULL)
            return nodeDeletion(to_delete_node);
        
        else if(to_delete_parent->left == to_delete_node)
        {
             to_delete_parent->left = nodeDeletion(to_delete_node);
        }
        
        else
        {
            to_delete_parent->right = nodeDeletion(to_delete_node);
        }
        
        return root;
    }
};