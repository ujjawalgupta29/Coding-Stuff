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
    
    unordered_map<TreeNode*, TreeNode*> mp;
    
    void dfs(TreeNode* root, TreeNode* parent)
    {
        if(!root)
            return;
        
        mp[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, NULL);        
        
        unordered_set<TreeNode*> visited;
        int level = 0;
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        
        while(level != K)
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node->left && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                
                if(node->right && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                
                if(mp[node] && visited.find(mp[node]) == visited.end())
                {
                    q.push(mp[node]);
                    visited.insert(mp[node]);
                }
            }
            level++;
        }
        
        vector<int> res;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        
        return res;
    }
};