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

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int counts = 0;
    
    int odds(vector<int> &digits)
    {
        int cnts=0;
        for(int i=1; i<=9; i++)
        {
            if(digits[i] % 2 != 0)
                cnts++;
        }
        return cnts;
    }
    
    void check(TreeNode* root, vector<int> digits)
    {
        if(root == NULL)
            return;
        
                
        digits[root->val]++;
        
        if(root->left == NULL && root->right == NULL)
        {
            if(odds(digits) == 0 || odds(digits) == 1)
                counts++;
        }
        
        check(root->left, digits);
        check(root->right, digits);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digits(10, 0);
        check(root, digits);  
        return counts;
    }
};