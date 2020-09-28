// vector<vector<int>> dir{
//     {-1,0}, {1,0},
//     {0,-1}, {0,1}
// };

int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<int>> cost(A, vector<int>(B, INT_MAX));
    cost[0][0] = 0;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        int curr_cost = cost[x][y];
        char ch = C[x][y];
        
        if(ch == 'U')
        {
            if(x-1 >= 0 && cost[x-1][y] > curr_cost)
            {
                cost[x-1][y] = curr_cost;
                q.push({x-1, y});
            }
            
            if(x+1 < A && cost[x+1][y] > curr_cost + 1)
            {
                cost[x+1][y] = curr_cost + 1;
                q.push({x+1, y});
            }
            
            if(y-1 >= 0 && cost[x][y-1] > curr_cost + 1)
            {
                cost[x][y-1] = curr_cost + 1;
                q.push({x, y-1});
            }
            
            if(y+1 < B && cost[x][y+1] > curr_cost + 1)
            {
                cost[x][y+1] = curr_cost + 1;
                q.push({x, y+1});
            }
        }
    
        if(ch == 'L')
        {
            if(x-1 >= 0 && cost[x-1][y] > curr_cost+1)
            {
                cost[x-1][y] = curr_cost+1;
                q.push({x-1, y});
            }
            
            if(x+1 < A && cost[x+1][y] > curr_cost + 1)
            {
                cost[x+1][y] = curr_cost + 1;
                q.push({x+1, y});
            }
            
            if(y-1 >= 0 && cost[x][y-1] > curr_cost)
            {
                cost[x][y-1] = curr_cost;
                q.push({x, y-1});
            }
            
            if(y+1 < B && cost[x][y+1] > curr_cost + 1)
            {
                cost[x][y+1] = curr_cost + 1;
                q.push({x, y+1});
            }
        }
        
        if(ch == 'R')
        {
            if(x-1 >= 0 && cost[x-1][y] > curr_cost+1)
            {
                cost[x-1][y] = curr_cost + 1;
                q.push({x-1, y});
            }
            
            if(x+1 < A && cost[x+1][y] > curr_cost + 1)
            {
                cost[x+1][y] = curr_cost + 1;
                q.push({x+1, y});
            }
            
            if(y-1 >= 0 && cost[x][y-1] > curr_cost + 1)
            {
                cost[x][y-1] = curr_cost + 1;
                q.push({x, y-1});
            }
            
            if(y+1 < B && cost[x][y+1] > curr_cost)
            {
                cost[x][y+1] = curr_cost;
                q.push({x, y+1});
            }
        }
        
        if(ch == 'D')
        {
            if(x-1 >= 0 && cost[x-1][y] > curr_cost+1)
            {
                cost[x-1][y] = curr_cost + 1;
                q.push({x-1, y});
            }
            
            if(x+1 < A && cost[x+1][y] > curr_cost)
            {
                cost[x+1][y] = curr_cost;
                q.push({x+1, y});
            }
            
            if(y-1 >= 0 && cost[x][y-1] > curr_cost + 1)
            {
                cost[x][y-1] = curr_cost + 1;
                q.push({x, y-1});
            }
            
            if(y+1 < B && cost[x][y+1] > curr_cost + 1)
            {
                cost[x][y+1] = curr_cost + 1;
                q.push({x, y+1});
            }
        }
        
    }
    
    return cost[A-1][B-1];
}
