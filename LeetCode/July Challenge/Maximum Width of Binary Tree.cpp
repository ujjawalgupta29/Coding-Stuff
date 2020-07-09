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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int max_len = INT_MIN;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            int sz = q.size();
            int first, second;
            
            int min_id = q.front().second;
            for(int i=0; i<sz; i++)
            {
                int curr_id = q.front().second - min_id;
                auto node = q.front().first;
                q.pop();
                
                if(i == 0)
                    first = curr_id;
                
                if(i == sz - 1)
                    second = curr_id;
                
                if(node->left)
                {
                    q.push({node->left, curr_id*2});
                }

                if(node->right)
                {
                    q.push({node->right, curr_id*2+1});
                    
                }
            }
            
            max_len = max(max_len, second - first + 1);
        }
        
        return max_len;
    }
};