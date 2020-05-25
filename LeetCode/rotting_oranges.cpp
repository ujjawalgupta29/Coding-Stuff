class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int counts = 0, days = -1;
        queue<pair<int, int>> q;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] > 0)
                    counts++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        while(!q.empty())
        {
            days++;
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                auto p = q.front();
                counts--;
                q.pop();
                
                for(int j=0; j<4; j++)
                {
                    int x = dir[j][0] + p.first;
                    int y = dir[j][1] + p.second;
                    
                    if(x < 0 || y < 0 || x >= m || y>= n || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        
        if(counts == 0)
            return max(0, days);
        
        else
            return -1;
    }
    
};