#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[11][51];

int solve(int n, int k)
{
    if(n == 1 || k == 0 || k == 1)
        return k;
        
    if(dp[n][k] != -1)
        return dp[n][k];
        
    int res, mini = INT_MAX;
    for(int f=1; f<=k; f++)
    {
        res = (max(solve(n, k-f), solve(n-1, f-1)));
        if(res < mini)
            mini = res;
    }
    
    return dp[n][k] = mini + 1;
}

int main()
{
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        
        cout << solve(n, k) << endl;
    }
}