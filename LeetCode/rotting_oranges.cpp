static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m)
            return 0;
        
        int n = grid[0].size();
        if(!n)
            return 0;
        
        int fresh_oranges = 0;
        int time = -1;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    fresh_oranges++;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        while(!q.empty())
        {
            int sz = q.size();
            time++;
            
            for(int i=0; i<sz; i++)
            {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                
                for(int d=0; d<4; d++)
                {
                    int r = x + dir[d];
                    int c = y + dir[d+1];
                    
                    if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1)
                        continue;
                    fresh_oranges--;
                    grid[r][c] = 2;
                    q.push({r, c});
                }
            }
                
        }
        
        if(fresh_oranges == 0)
            return max(0, time);
        
        return -1;
    }
};