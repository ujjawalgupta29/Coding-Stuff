#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1003;

long long int dp[103][103][2];

int solve(string s)
{
    int n = s.size();
    
    if(n == 0)
        return 0;
        
    for(int i=0; i<n; i+=2)
    {
        if(s[i] == 'T')
        {
            dp[i][i][1] = 1;
            dp[i][i][0] = 0;
        }
        else
        {
            dp[i][i][1] = 0;
            dp[i][i][0] = 1;
        }
    }
    
    for(int l=3; l<=n; l++)
    {
        for(int i=0; i<=n-l; i++)
        {
            int j = i+l-1;
            
            for(int k=i+1; k<j; k+=2)
            {
                if(s[k] == '&')
                {
                    dp[i][j][1] += dp[i][k-1][1] * dp[k+1][j][1];
                    dp[i][j][0] += dp[i][k-1][0] * dp[k+1][j][1] + 
                                    dp[i][k-1][1] * dp[k+1][j][0] +
                                    dp[i][k-1][0] * dp[k+1][j][0];
                }
                
                else if(s[k] == '^')
                {
                    dp[i][j][1] += dp[i][k-1][0] * dp[k+1][j][1] + 
                                    dp[i][k-1][1] * dp[k+1][j][0];
                    dp[i][j][0] += dp[i][k-1][1] * dp[k+1][j][1] +
                                    dp[i][k-1][0] * dp[k+1][j][0];
                }
                
                else
                {
                    dp[i][j][0] += dp[i][k-1][0] * dp[k+1][j][0];
                    dp[i][j][1] += dp[i][k-1][0] * dp[k+1][j][1] + 
                                    dp[i][k-1][1] * dp[k+1][j][0] +
                                    dp[i][k-1][1] * dp[k+1][j][1];
                }
            }
            
            dp[i][j][0] %= mod;
            dp[i][j][1] %= mod;
        }
    }
    
    return dp[0][n-1][1];
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        memset(dp, 0, sizeof(dp));
        
        cout << solve(s) << endl;
    }
}