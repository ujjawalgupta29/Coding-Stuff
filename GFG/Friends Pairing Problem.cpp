#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1] + (i-1)*dp[i-2]) % mod;
        }
        
        cout << dp[n] << endl;
        
    }
}