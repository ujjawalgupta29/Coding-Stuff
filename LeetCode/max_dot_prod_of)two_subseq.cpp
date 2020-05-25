class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++)
        {
            dp[i][0] = nums1[i] * nums2[0];
            if(i > 0)
                dp[i][0] = max(dp[i][0], dp[i-1][0]);
        }
        
        for(int i=0; i<n; i++)
        {
            dp[0][i] = nums1[0] * nums2[i];
            if(i > 0)
                dp[0][i] = max(dp[0][i], dp[0][i-1]);
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                int mult = nums1[i] * nums2[j];
                dp[i][j] = max(max(mult, mult+dp[i-1][j-1]), max(dp[i-1][j], dp[i][j-1]) );
            }
        }
        
        return dp[m-1][n-1];
    }
};