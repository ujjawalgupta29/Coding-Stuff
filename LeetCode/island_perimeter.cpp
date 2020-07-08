class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        
        int counts = 0;
        int repeat = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                     counts++;
                    if(i!=0 && grid[i-1][j])
                        repeat++;

                    if(j!=0 && grid[i][j-1])
                        repeat++;
                }
            }
        }
        
        return counts*4 - 2*repeat;
    }
};