void helper(Node* root)
{
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL)
    {
        counts++;
    }
    
    helper(root->left);
    helper(root->right);
}

int countLeaves(Node* root)
{
  // Your code here
  int counts = 0;
  helper(root, counts);
  return counts;
}