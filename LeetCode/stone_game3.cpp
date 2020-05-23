class Solution {
public:
    
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<int> dp(n, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            int ans = s[i] - dp[i+1];
            if(i+1 < s.size())
                ans = max(ans, s[i] + s[i+1] - dp[i+2] );
            if(i+2 < s.size())
                ans = max(ans, s[i] + s[i+1] + s[i+2] - dp[i+3] );

            dp[i] = ans;
        }
        
        int alice_score = dp[0];
        
        if(alice_score > 0)
            return "Alice";
        else if(alice_score == 0)
            return "Tie";
        
        return "Bob";
    }
};