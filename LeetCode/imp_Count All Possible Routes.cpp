class Solution {
public:
    
    int mod = 1e9+7;
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n+1, vector<int>(fuel+1, -1));
        
        return solve(locations, start, finish, fuel, dp);
    }
    
    int solve(vector<int>& locations, int curr_city, int end,
              int fuel, vector<vector<int>> &dp)
    {
        if(fuel < 0)
            return 0;
        
        if(dp[curr_city][fuel] != -1)
            return dp[curr_city][fuel];
        
        long long ans = 0;
        
        if(curr_city == end)
            ans = 1;
        
        for(int i=0; i<locations.size(); i++)
        {
            if(i != curr_city)
                ans = (ans + solve(locations, i, end, fuel - 
                                   abs(locations[i]-locations[curr_city]), dp)) % mod;
        }
        
        return dp[curr_city][fuel] = ans;
    }
};