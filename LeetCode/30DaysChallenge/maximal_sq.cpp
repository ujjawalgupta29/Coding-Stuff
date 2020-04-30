class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        if(n == 0)
            return 0;
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        int max_area = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = (matrix[i][j] - '0');
                
                else if(matrix[i][j] == '1')
                {
                    int temp = min(dp[i-1][j-1], dp[i-1][j]);
                    dp[i][j] = min(temp, dp[i][j-1]) + 1;
                }
                max_area = max(max_area, dp[i][j]);
            }
        }
        
        return max_area * max_area;
    }
};