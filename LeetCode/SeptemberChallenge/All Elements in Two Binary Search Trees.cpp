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

    void dfs(TreeNode* root, vector<int> &tree)
    {
        if(root == NULL)
            return;
        
        dfs(root->left, tree);
        tree.push_back(root->val);
        dfs(root->right, tree);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        
        dfs(root1, tree1);
        dfs(root2, tree2);
        
        int l1 = tree1.size();
        int l2 = tree2.size();
        
        int i=0, j=0;
        vector<int> res;
        
        while(i < l1 && j < l2)
        {
            if(tree1[i] <= tree2[j])
            {
                res.push_back(tree1[i]);
                i++;
            }
            
            else
            {
                res.push_back(tree2[j]);
                j++;
            }
        }
        
        while(i < l1)
        {
            res.push_back(tree1[i]);
            i++;
        }
        
        while(j < l2)
        {
            res.push_back(tree2[j]);
            j++;
        }
        
        return res;
    }
};