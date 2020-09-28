bool is_identical(TreeNode* A, TreeNode* B){
    if (A == NULL && B == NULL)
        return true;
    else if (A == NULL || B == NULL)
        return false;

    return ((A->val == B->val) && is_identical(A->left, B->left) && is_identical(A->right, B->right));
}

bool isSubtree(TreeNode* r1, TreeNode* r2) {
 	// first is a subtree of s
    if(r2 == NULL)
        return 1;

    if(r1 == NULL)
        return 0;

    if(is_identical(r1, r2))
        return true;

    return isSubtree(r1->left, r2) || isSubtree(r1->right, r2)

}

int foo(TreeNode* A){
	if(A == NULL)
        return 0;

    int nodes = 1;

    nodes += foo(A->left) + foo(A->right);

    return nodes;
}

int Solution(TreeNode* T1, TreeNode* T2){
	if (isSubtree(T2, T1)){
		return foo(T2);
	}else{
		return 0;
	}
}