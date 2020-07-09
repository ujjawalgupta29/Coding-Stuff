/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void getLeftNodes(TreeNode* A, bool &flag1, vector<int> &left)
{
    if(flag1)
        return;
        
    if(A == NULL)
        return;
        
    if(!A->left && !A->right)
        flag1 = 1;
        
    left.push_back(A->val);
    getLeftNodes(A->left, flag1, left);
    getLeftNodes(A->right, flag1, left);
}

void getRightNodes(TreeNode* A, bool &flag2, vector<int> &right)
{
    if(flag2)
        return;
        
    if(A == NULL)
        return;
        
    if(!A->left && !A->right)
        flag2 = 1;
        
    right.push_back(A->val);
    getRightNodes(A->right, flag2, right);
    getRightNodes(A->left, flag2, right);
}

void getLeaves(TreeNode* A, vector<int> &leaves)
{
    if(A == NULL)
        return;
        
    if(!A->left && !A->right)
        leaves.push_back(A->val);
        
    getLeaves(A->left, leaves);
    getLeaves(A->right, leaves);
}

vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> res;
    vector<int> left;
    vector<int> right;
    vector<int> leaves;
    
    if(A == NULL)
        return res;
        
    bool flag1=0, flag2=0;
    
    getLeftNodes(A->left, flag1, left);
    getRightNodes(A->right, flag2, right);
    getLeaves(A, leaves);
    
    // for(int x : left)
    //     cout << x << " ";
    // cout<<endl;
    
    // for(int x : right)
    //     cout << x << " ";
    // cout<<endl;
    
    // for(int x : leaves)
    //     cout << x << " ";
    // cout<<endl;
    
    res.push_back(A->val);
    for(int x : left)
    {
        res.push_back(x);
    }
    
    int n = leaves.size();
    for(int i=1; i<n-1; i++)
    {
        res.push_back(leaves[i]);
    }
    
    reverse(right.begin(), right.end());
    for(int x : right)
    {
        res.push_back(x);
    }
    
    return res;
}


































