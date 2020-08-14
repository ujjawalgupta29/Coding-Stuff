// class Solution {
// public:
    
//     int dp[102][102] = {0};
    
//     int dfs(vector<int> &cuts, int i, int j)
//     {
//         if(j - i <= 1)
//             return 0;
        
//         if(!dp[i][j])
//         {
//             dp[i][j] = INT_MAX;

//             for(int k=i+1; k<j; k++)
//             {
//                 dp[i][j] = min(dp[i][j],
//                               cuts[j] - cuts[i] + dfs(cuts, i,k) + dfs(cuts, k, j));
//             }
//         }
        
//         return dp[i][j];
//     }
    
//     int minCost(int n, vector<int>& cuts) {
//         cuts.push_back(0);
//         cuts.push_back(n);
//         sort(cuts.begin(), cuts.end());
//         int N = cuts.size();
//         return dfs(cuts, 0, N-1);
//     }
// };

class Solution {
public:
    int minCost(int len, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(len);
        sort(cuts.begin(), cuts.end());
        
        int n = cuts.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for(int i=0; i<n-1; i++)
            dp[i][i+1] = 0;
        
        for(int i=0; i<n-2; i++)
            dp[i][i+2] = cuts[i+2] - cuts[i];
        
        for(int l=4; l<=n; l++)
        {
            for(int i=0; i<=n-l; i++)
            {
                int j = i + l - 1;
                
                for(int k=i+1; k<j; k++)
                {
                    dp[i][j] = min(dp[i][j], 
                                  cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};