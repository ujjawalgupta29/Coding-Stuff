

/*
          2
        1    3
    4            9
       10       8    
     6

     []
     []
     []
     [1,3]
     [2]
*/

void traverse(root, int level)
{
    if(root == NULL)
        return;


    arr[ht-level].push_back(root->data);
    traverse(root->left, level+1);
    traverse(root->right, level+1);
}