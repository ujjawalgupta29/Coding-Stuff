class Solution {
public:
    int way[52][52][12];
    int apples[51][51];
    int m,n;
    int mod = 1e9 + 7;
    
    
    int dp(int r, int c, int cuts)
    {
        if(way[r][c][cuts] != -1)
            return way[r][c][cuts];
        
        if(cuts == 0)
        {
            return (apples[r][c] > 0) ? 1 : 0;
        }
        
        way[r][c][cuts] = 0;
        
        for(int i=r+1; i<m; i++)
        {
            if(apples[r][c] - apples[i][c] > 0 && apples[i][c] >= cuts)
                way[r][c][cuts] = (way[r][c][cuts] + dp(i, c, cuts-1)) % mod;
        }
        
        for(int j=c+1; j<n; j++)
        {
            if(apples[r][c] - apples[r][j] > 0 && apples[r][j] >= cuts)
                way[r][c][cuts] = (way[r][c][cuts] + dp(r, j, cuts-1)) % mod;
        }
        
        return way[r][c][cuts];
    }
    
    int ways(vector<string>& pizza, int k) {
        memset(apples, 0, sizeof(apples));
        m = pizza.size();
        n = pizza[0].size();
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                apples[i][j] = apples[i][j+1];
                for(int l = i; l<m; l++)
                    apples[i][j] += (pizza[l][j] == 'A');
            }
        }
        
        memset(way, -1, sizeof(way));
        
        return dp(0,0,k-1);
    }
};