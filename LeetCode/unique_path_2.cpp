class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0] || grid[m-1][n-1])
            return 0;

        vector<vector<long long>> paths(m, vector<long long>(n, 0));
        
        for(int i=0; i<n; i++)
        {
            if(grid[0][i] == 0)
                paths[0][i] = 1;
            else 
                break;
        }
        
        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 0)
                paths[i][0] = 1;
            else 
                break;
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(grid[i][j])
                    paths[i][j] = 0;
                
                else
                {
                    paths[i][j] = paths[i][j-1] + paths[i-1][j];
                }
            }
        }

        return (int)paths[m-1][n-1];
    }
};