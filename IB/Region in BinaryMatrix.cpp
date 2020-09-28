vector<vector<int>> dir = {
  {-1, -1}, {-1, 0}, {-1, 1},
  {0, -1}, {0, 1},
  {1, -1}, {1, 0}, {1, 1}
};

int dfs(vector<vector<int>> &A, int i, int j, int m, int n)
{
    if(i < 0 || j < 0 || i >= m || j >= n || A[i][j] != 1)
        return 0;
        
    A[i][j] = 2;
    
    int size = 1;
    
    for(int d=0; d<8; d++)
    {
        size += dfs(A, i+dir[d][0], j+dir[d][1], m, n);
    }
    
    return size;
}

int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    
    int max_size = 0;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            max_size = max(max_size, dfs(A, i, j, m, n));
        }
    }
    
    return max_size;
}
