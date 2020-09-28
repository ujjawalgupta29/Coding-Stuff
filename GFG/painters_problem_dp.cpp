#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> &nums, int k, int n)
{
    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
    
    vector<int> preSum(n+1, 0);
    
    for(int i=0; i<n; i++)
    {
        preSum[i+1] = preSum[i] + nums[i];
    }
    
    for(int i=1; i<=n; i++)
        dp[1][i] = preSum[i];
        
    for(int j=1; j<=k; j++)
        dp[j][1] = nums[0];
        
    for(int i=2; i<=k; i++)
    {
        for(int j=2; j<=n; j++)
        {
            dp[i][j] = INT_MAX;
            for(int p=1; p<=j; p++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i-1][p], preSum[j] - preSum[p]));
            }
        }
    }
    
    return dp[k][n];
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int k, n;
        cin >> k >> n;
        
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        cout << solve(nums, k, n) << endl;
    }
}