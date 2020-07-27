#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == s[j-1] && i != j)
                {
                    dp[i][j] = max(1+dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
                }
                
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);   
                }
            }
        }
        
        cout << dp[n][n] << endl;
    }
}