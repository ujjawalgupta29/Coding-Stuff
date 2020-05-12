class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n<3)
            return 0;
        
        vector<pair<int, int>> dp(n);
        int counts = 0;
        dp[0] = {0,0};
        dp[1] = {A[1]-A[0], 2};
        
        for(int i=2; i<n; i++)
        {
            int diff = A[i] - A[i-1];
            if(dp[i-1].first == diff)
            {
                dp[i].first = diff;
                dp[i].second = dp[i-1].second + 1;
            }
            else
            {
                dp[i].first = diff;
                dp[i].second = 2;
            }
            if(dp[i].second >= 3)
            {
                counts += (dp[i].second - 3 + 1);
            }
        }
        
        return counts;
    }
};