bool isSafe(int x, int y, vector<vector<bool>> &visited,
            vector<int> &cx, vector<int> &cy, int n, int r, int A, int B)
{
    if(x < 0 || y < 0 || x > A || y > B || visited[x][y])
        return false;
        
    //check for circles
    for(int i=0; i<n; i++)
    {
        int inside = (x-cx[i])*(x-cx[i]) + (y-cy[i])*(y-cy[i]) - r*r;
        if(inside <= 0)
            return false;
    }
        
    return true;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(A+1, vector<bool>(B+1, 0));
    q.push({0,0});
    visited[0][0] = 1;
    
    vector<vector<int>> dir{
      {-1,-1}, {-1,0}, {-1,1},
      {0, -1}, {0,1},
      {1,-1}, {1,0}, {1,1} };
    
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        
        if(x == A && y == B)
            return "YES";
        
        for(int i=0; i<8; i++)
        {
            if(isSafe(x+dir[i][0], y+dir[i][1], visited, E, F, C, D, A, B))
            {
                q.push({x+dir[i][0], y+dir[i][1]});
                visited[x+dir[i][0]][y+dir[i][1]] = 1;
            }
        }
    }
    
    return "NO";
}
