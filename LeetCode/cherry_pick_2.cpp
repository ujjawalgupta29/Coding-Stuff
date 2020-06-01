class Solution {
public:
    
    int dp[71][71][71];
    
    int helper(vector<vector<int>>& grid, int row, int col1, int col2, int m, int n)
    {
        if(col1 < 0 || col2 < 0 || col1 == n || col2 == n)
            return INT_MIN;
        
        if(row == m)
            return 0;
        
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        
        int ans = grid[row][col1] + ( (col1 == col2) ? 0 : grid[row][col2] );
        int op = 0;
        
        for(int x = -1; x < 2; x++)
        {
            for(int y = -1; y < 2; y++)
            {
                op = max(op, helper(grid, row+1, col1 + x, col2 + y, m, n));
            }
        }
        
        return dp[row][col1][col2] = ans + op;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0, n-1, m, n);
    }
};