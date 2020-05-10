class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        if(m == 0)
            return matrix;
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = matrix[0][0];
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] + matrix[i][j];
                
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int s1 = (i-k) >= 0 ? (i-k) : 0;
                int e1 = (j-k) >= 0 ? (j-k) : 0;
                int s2 = (i+k) < m ? (i+k) : m-1;
                int e2 = (j+k) < n ? (j+k) : n-1;
                
                matrix[i][j] = dp[s2][e2];
                
                if(s1 >= 1 && e1 >= 1)
                {
                    matrix[i][j] += dp[s1-1][e1-1];
                }
                
                if(s1 >= 1)
                {
                    matrix[i][j] -= dp[s1-1][e2];
                }
                
                if(e1 >= 1)
                {
                    matrix[i][j] -= dp[s2][e1-1];
                }
            }
        }
        
        return matrix;
    }
};