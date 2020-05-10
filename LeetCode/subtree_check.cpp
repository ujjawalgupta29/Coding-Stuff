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
// O(n + km) n->nodes in s, m->nides in t, k-> nodes in s = root t ki val
//O(log(n) + log(m)) ->Space
class Solution {
public:
    bool check = false;
    
    bool compare(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL || s->val != t->val)
            return false;
        
        return compare(s->left, t->left) && compare(s->right, t->right);
    }
    
    void traverse(TreeNode* root, TreeNode* t)
    {
        if(root == NULL || check)
            return;
        
        if(root->val == t->val)
        {
            check = compare(root, t);
        }
        
        traverse(root->left, t);
        traverse(root->right, t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL)
            return 1;
        traverse(s, t);
        return check;
    }
};
static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();