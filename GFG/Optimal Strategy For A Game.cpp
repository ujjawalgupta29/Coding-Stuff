#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101][101];

int solve(vector<int> &nums, int s, int e)
{
    if(s > e)
        return 0;
        
    if(e-s == 1)
        return max(nums[s], nums[e]);
        
    if(dp[s][e] != -1)
        return dp[s][e];
        
    int res = 0;
    
    // res += max(nums[s] + solve(nums, s+2, e), 
    //         max(max(nums[s], nums[e]) + solve(nums, s+1, e-1),
    //             nums[e] + solve(nums, s, e-2)));
                
    int res1 = nums[s] + min(solve(nums, s+2, e), solve(nums, s+1, e-1));
    int res2 = nums[e] + min(solve(nums, s+1, e-1), solve(nums, s, e-2));
    
    res = max(res1, res2);
    
    return dp[s][e] = res;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        cout << solve(nums, 0, n-1) << endl;
    }
}