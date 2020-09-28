class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        
        return solve(days, costs, dp, n, 0);
    }
    
    int solve(vector<int> &days, vector<int> &costs, vector<int> &dp, int n, int i)
    {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = costs[0] + solve(days, costs, dp, n, i+1);
        
        int idx;
        for(idx=i; idx<n; idx++)
        {
            if(days[idx] >= days[i] + 7)
                break;
        }
        
        ans = min(ans, costs[1] + solve(days, costs, dp, n, idx));
        
        for(idx=i; idx<n; idx++)
        {
            if(days[idx] >= days[i] + 30)
                break;
        }
        
        ans = min(ans, costs[2] + solve(days, costs, dp, n, idx));
        
        return dp[i] = ans;
    }
};