class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int dp[366];
        memset(dp, 0, sizeof(dp));
        int n = days.size();
        
        for(int day : days)
            dp[day] = cost[0];
        
        for(int i=1; i<=days[n-1]; i++)
        {
            if(!dp[i])
                dp[i] = dp[i-1];
            
            else
            {
                dp[i] = dp[i-1] + cost[0];
                int idx = max(0, i-7);
                dp[i] = min(dp[i], dp[idx] + cost[1]);
                idx = max(0, i-30);
                dp[i] = min(dp[i], dp[idx] + cost[2]);
            }
        }
        
        return dp[days[n-1]];
    }
};