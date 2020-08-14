#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> &nums, int w, int n)
{
    vector<long> dp(w+1, INT_MAX);
    dp[0] = 0;
    
    for(int i=1; i<=w; i++)
    {
        if(n >= i && nums[i-1] != -1)
            dp[i] = nums[i-1];
            
        for(int j=i-1; j>=1; j--)
        {
            if(dp[j] != INT_MAX)
                dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
    
    // for(int x : dp)
    //     cout << x << " ";
        
    // cout << endl;
    
    return (dp[w] == INT_MAX) ? -1 : dp[w];
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, w;
        cin >> n >> w;
        
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        cout << solve(nums, w, n) << endl;
    }
}