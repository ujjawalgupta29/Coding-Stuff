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
    
    map<int, map<int, set<int>>> mp;
    
    void traverse(TreeNode* root, int x, int y)
    {
        if(root == NULL)
            return;
        
        mp[x][y].insert(root->val);
        traverse(root->left, x-1, y+1);
        traverse(root->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        
        vector<vector<int>> res;
        
        for(auto p : mp)
        {
            vector<int> temp;
            for(auto q : p.second)
            {
                temp.insert(temp.end(), q.second.begin(), q.second.end());   
            }
            res.push_back(temp);
        }
        
        return res;
    }
};