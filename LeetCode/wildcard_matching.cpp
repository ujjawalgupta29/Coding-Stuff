static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        
        vector<vector<bool>> dp(len_p+1, vector<bool>(len_s+1, 0));
        dp[0][0] = 1;
        
        for(int i=1; i<len_p+1; i++)
        {
            if(p[i-1] == '*')
                dp[i][0] = 1;
            else 
                break;
        }
        
        for(int i=1; i<len_p+1; i++)
        {
            for(int j=1; j<len_s+1; j++)
            {
                if(p[i-1] == '*')
                {
                    if(dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1])
                        dp[i][j] = 1;
                }
                
                else if(p[i-1] == '?')
                {
                    if(dp[i-1][j-1])
                        dp[i][j] = 1;
                }
                
                else
                {
                    if(s[j-1] == p[i-1])
                    {
                        if(dp[i-1][j-1])
                            dp[i][j] = 1;
                    }
                }
            }
        }
        
        return dp[len_p][len_s];
    }
};