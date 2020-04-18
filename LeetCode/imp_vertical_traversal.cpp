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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, set<int>>> nodes;
        queue< pair<TreeNode*, pair<int, int>> > q;
        
        if(root == NULL)
            return res;
        
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                TreeNode* temp = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();
                
                nodes[x][y].insert(temp->val);
                
                if(temp->left)
                    q.push({temp->left, {x-1, y+1}});
                if(temp->right)
                    q.push({temp->right, {x+1, y+1}});
            }
        }
        
        for(auto p : nodes)
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