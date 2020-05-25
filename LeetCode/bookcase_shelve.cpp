class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int sw) 
    {
        int n = books.size();
        vector<int> dp(n + 1, 0);  
        dp[0] = 0;
        
        for(int i=0; i<n; i++)
        {
            dp[i+1] = dp[i] + books[i][1];
            int ht = books[i][1];
            int wt = books[i][0];
            
            for(int j=i-1; j>=0; j--)
            {
                if(wt + books[j][0] > sw)
                    break;
                
                wt += books[j][0];
                ht = max(ht, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + ht);
            }
        }
        
        return dp[n];
    }
};