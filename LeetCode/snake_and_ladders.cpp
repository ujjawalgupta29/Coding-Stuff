class Solution {
public:
    
    pair<int, int> get_coordi(int x, int n)
    {
        int r = n - (x-1)/n -1;
        int c = (x-1)%n;
        
        if(r%2==n%2)
            return {r,n-c-1};
        
        return {r, c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;
        
        queue<int> q;
        q.push(1);
        
        vector<vector<bool>> visited(n, vector<bool>(n,0));
        visited[n-1][0] = 1;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                int num = q.front();
                q.pop();
                
                if(num == n*n)
                    return steps;
                
                for(int i=1; i<=6; i++)
                {
                    if(num+i <= n*n)
                    {
                        auto coordi = get_coordi(num+i, n);
                        int x1 = coordi.first;
                        int y1 = coordi.second;
                        
                        if(!visited[x1][y1])
                        {
                            visited[x1][y1] = 1;
                            if(board[x1][y1] == -1)
                                q.push(num+i);
                            
                            else
                                q.push(board[x1][y1]);
                        }
                    }
                }
                
                
                
            }
            steps++;
        }
        
        return -1;
    }
};