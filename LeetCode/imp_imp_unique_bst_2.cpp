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
    
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> list;
        if(start > end)
        {
            list.push_back(NULL);
            return list;            
        }
        
        if(start == end)
        {
            list.push_back(new TreeNode(start));
            return list;
        }
        
        for(int i=start; i<=end; i++)
        {
            auto left = generate(start, i-1);
            auto right = generate(i+1, end);
            
            for(auto rNode : right)
            {
                for(auto lNode : left)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lNode;
                    root->right = rNode;
                    list.push_back(root);
                }
            }
        }
        
        return list;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>();
        return generate(1, n);
    }
};