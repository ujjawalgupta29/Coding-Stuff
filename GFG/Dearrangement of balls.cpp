#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1e9+7;

int solve(int n)
{
    if(n <= 3)
        return n-1;
        
    vector<long> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    
    for(int i=4; i<=n; i++)
    {
        dp[i] = ((i-1) * ((dp[i-1] + dp[i-2])%mod)%mod);
    }
    
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        cout << solve(n) << endl;
    }
}