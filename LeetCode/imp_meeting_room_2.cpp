int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    priority_queue<int, vector<int>, greater<int>> min_heap;
    sort(A.begin(), A.end());
    min_heap.push(A[0][1]);
    
    for(int i=1; i<n; i++)
    {
        if(A[i][0] >= min_heap.top())
            min_heap.pop();
        min_heap.push(A[i][1]);
    }
    
    return min_heap.size();
}
