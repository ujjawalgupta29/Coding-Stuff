class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        int dp[len][len];
        
        for(int i=0; i<len; i++)
            dp[i][i] = 1;
        
        for(int i=0; i<len-1; i++)
        {
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        }
        
        for(int l=3; l <= len; l++)
        {
            for(int i=0; i<=len-l; i++)
            {
                int start = i;
                int end = i + l - 1;
                if(s[start] == s[end])
                    dp[start][end] = dp[start+1][end-1] + 2;
                else
                    dp[start][end] = max(dp[start][end-1], dp[start+1][end]);
            }
        }

        return dp[0][len-1];
    }
};