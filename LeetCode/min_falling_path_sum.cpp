class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        if(m == 0)
            return 0;
        int n = A[0].size();
        if(n == 0)
            return 0;
        
        int mini = INT_MAX;
        
        if(m == 1)
        {
            for(int i=0; i<n; i++)
                mini = min(mini, A[0][i]);
            return mini;
        }
        
        vector<vector<int>> grid(m, vector<int>(n, INT_MAX));
        
        for(int i=0; i<n; i++)
            grid[0][i] = A[0][i];
        
        for(int i=0; i<m-1; i++)
        {
            for(int j=0; j<n; j++)
            {
                int a, b, c;
                a = c = INT_MAX;
                
                b = grid[i][j];
                if(j-1 >= 0)
                    a = grid[i][j-1];
                if(j+1 < n)
                    c = grid[i][j+1];
                
                int result = (a < b) ? min(a, c) : min(b,c);
                
                grid[i+1][j] = A[i+1][j] + result;
                if(i == m-2)
                    mini = min(mini, grid[i+1][j]);
            }
        }
        
        // for(int i = 0 ;i < m ; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //         cout << grid[i][j] << " ";
        //     cout << endl;
        // }
        // cout << mini << endl;
        
        return mini;
    }
};