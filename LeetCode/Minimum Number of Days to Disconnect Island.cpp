class Solution {
public:
    
    void dfs(int i, int j, vector<vector<bool>> &visited, 
             vector<vector<int>>& grid, int m, int n)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        visited[i][j] = 1;
        
        dfs(i+1, j, visited, grid, m, n);
        dfs(i, j+1, visited, grid, m, n);
        dfs(i-1, j, visited, grid, m, n);
        dfs(i, j-1, visited, grid, m, n);
    }
    
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int islands = count_islands(grid, m, n);
        // cout << islands << endl;
        
        if(islands == 0 || islands > 1)
            return 0;
        
        else
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(grid[i][j])
                    {
                        grid[i][j] = 0;
                        int curr_islands = count_islands(grid, m, n);
                        grid[i][j] = 1;
                        
                        if(curr_islands == 0 || curr_islands > 1)
                            return 1;
                    }
                }
            }
        }
        
        return 2;
    }
    
    int count_islands(vector<vector<int>> &grid, int m, int n)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int islands = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] && !visited[i][j])
                {
                    dfs(i, j, visited, grid, m, n);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};