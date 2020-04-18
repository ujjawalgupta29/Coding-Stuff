class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        
        int n = grid[0].size();
        if(n == 0)
            return 0;
        
        int lands = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1')
                {
                    islands(grid, i, j, m, n);
                    lands++;
                }
            }
        }
        return lands;
    }
    
    void islands(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if( i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '\0' || grid[i][j] == '0')
            return;
        
        grid[i][j] = '\0';
        
        islands(grid, i+1, j, m, n);
        islands(grid, i, j+1, m, n);
        islands(grid, i-1, j, m, n);
        islands(grid, i, j-1, m, n);
    }
};