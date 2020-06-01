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
    unordered_map <TreeNode*, TreeNode*> mp;
    
    void dfs(TreeNode* root, TreeNode* parent)
    {
        if(root == NULL)
            return;
        
        mp[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, NULL);    
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> seen;
        
        q.push(target);
        seen.insert(target);
        int level = 0;
        
        while(level != K)
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL && seen.find(node->left) == seen.end())
                {
                    q.push(node->left);
                    seen.insert(node->left);
                }
                
                if(node->right != NULL && seen.find(node->right) == seen.end())
                {
                    q.push(node->right);
                    seen.insert(node->right);
                }
                
                if(mp[node] != NULL && seen.find(mp[node]) == seen.end())
                {
                    q.push(mp[node]);
                    seen.insert(mp[node]);
                }
            }
            level++;
        }
        
        vector<int> res;
        
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        
        return res;
    }
};