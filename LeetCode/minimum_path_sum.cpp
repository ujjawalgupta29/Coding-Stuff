class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> min_path(m, vector<int>(n, INT_MAX));
        min_path[0][0] = grid[0][0];
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j+1 < n)
                {
                    min_path[i][j+1] = min(min_path[i][j+1], min_path[i][j] + grid[i][j+1]);
                }
                if(i+1 < m)
                {
                    min_path[i+1][j] = min(min_path[i+1][j], min_path[i][j] + grid[i+1][j]);
                }
            }
        }
        
        // for(int i=0; i<m; i++)
        // {
        //     for(int j=0; j<n; j++)
        //         cout << min_path[i][j] << " ";
        //     cout << endl;
        // }
        
        return min_path[m-1][n-1];
    }
};