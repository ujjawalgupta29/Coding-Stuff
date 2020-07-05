class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        
        unordered_set<string> st(dict.begin(), dict.end());
        int n = s.size();
        vector<bool> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(dp[j])
                {
                    string str = s.substr(j, i-j);
                    if(st.find(str) != st.end())
                    {
                        dp[i] = 1;
                        break;
                    }    
                }
            }
        }
        
        return dp[n];
    }
};