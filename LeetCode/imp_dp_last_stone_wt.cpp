class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int S=0, S2 = 0;
        
        for(int x : stones)
            S += x;
        
        vector<vector<bool>> dp(S+1, vector<bool>(n+1));
        
        for(int i=0; i<=n; i++)
            dp[0][i] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int s=1; s<=S/2; s++)
            {
                if(dp[s][i-1] || (s >= stones[i-1] && dp[s-stones[i-1]][i-1]) )
                {
                    dp[s][i] = 1;
                    S2 = max(S2, s);
                }
            }
        }
        
        return S - 2*S2;
    }
};