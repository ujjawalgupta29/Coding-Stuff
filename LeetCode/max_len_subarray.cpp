class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int a = A.size();
        int b = B.size();
        
        vector<vector<int>> dp(a, vector<int>(b));
        int maximum = 0;
        
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = (A[i] == B[j]) ? 1 : 0;
                    maximum = max(maximum, dp[i][j]);
                }
                else if(A[i] == B[j])
                {
                    dp[i][j] = max(1+dp[i-1][j-1], 1);
                    maximum = max(maximum, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return maximum;
    }
};