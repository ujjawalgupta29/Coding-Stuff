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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            double num = 0;
            double sum = 0;
            for(int i=0; i<sz; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                num++;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            // if()
            res.push_back(sum/num);;
        }
        
        return res;
    }
};