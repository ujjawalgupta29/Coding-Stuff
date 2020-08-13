#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int longest(vector<int> &nums)
{
    int n = nums.size();
    if(n == 0)
        return 0;
    
    // vector<int> dp(n, 1);
    // int max_len = 1;
    
    // for(int i=1; i<n; i++)
    // {
    //     for(int j=i-1; j>=0; j--)
    //     {
    //         if(nums[i] - nums[j] == 1 || nums[i] == nums[j] - 1)
    //         {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
        
    //     max_len = max(max_len, dp[i]);
    // }
    
    // return max_len;
    
    int max_len = 1;
    unordered_map<int, int> mp;
    mp[nums[0]] = 1;
    
    for(int i=1; i<n; i++)
    {
        bool flag = 0;
        
        if(mp.find(nums[i] - 1) != mp.end())
        {
            mp[nums[i]] = max(mp[nums[i]], mp[nums[i] - 1] + 1);
            flag = 1;
        }
        
        if(mp.find(nums[i] + 1) != mp.end())
        {
            mp[nums[i]] = max(mp[nums[i]], mp[nums[i] + 1] + 1);
            flag = 1;
        }
        
        if(flag == 0)
            mp[nums[i]] = 1;
        
        max_len = max(max_len, mp[nums[i]]);
    }
    
    return max_len;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        cout << longest(nums) << endl;
    }
}