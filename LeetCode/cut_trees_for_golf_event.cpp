class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        
        vector<vector<int>> hts;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(forest[i][j] > 1)
                    hts.push_back({forest[i][j], i, j});
            }
        }
        
        sort(hts.begin(), hts.end());
        
        int ans = 0;
        
        for(int i=0, curr_row=0, curr_col=0; i<hts.size(); i++)
        {
            int steps = bfs(forest, curr_row, curr_col, hts[i][1], hts[i][2]);
            if(steps == -1)
                return -1;
            
            ans += steps;
            curr_row = hts[i][1];
            curr_col = hts[i][2];
        }
        
        return ans;
        
    }
    
    int bfs(vector<vector<int>>& forest, 
            int sr, int sc, int er, int ec)
    {
        if(sr == er && sc == ec)
            return 0;
        
        int m = forest.size();
        int n = forest[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        visited[sr][sc] = 1;
        
        int steps = 0;
        
        while(!q.empty())
        {
            steps++;
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int d=0; d<4; d++)
                {
                    int r = x + dir[d];
                    int c = y + dir[d+1];
                    
                    if(r < 0 || c < 0 || r >= m || c >= n ||
                       forest[r][c] == 0 || visited[r][c])
                        continue;
                    
                    if(r == er && c == ec)
                        return steps;
                    
                    q.push({r, c});
                    visited[r][c] = 1;
                }
            }
            
        }
        
        return -1;
    }
};