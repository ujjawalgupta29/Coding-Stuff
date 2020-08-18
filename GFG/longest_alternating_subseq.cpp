#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> &nums, int n)
{
    if(n == 0)
        return 0;
        
    vector<int> inc(n,1);
    vector<int> dec(n,1);
    int max_len = 1;
    
    for(int i=1; i<n; i++)
    {
        int min_count = 1;
        int max_count = 1;
        
        for(int j=i-1; j>=0; j--)
        {
            if(nums[j] < nums[i])
            {
                inc[i] = max(inc[i], dec[j] + 1);
            }
            if(nums[j] > nums[i])
            {
                dec[i] = max(dec[i], inc[j] + 1);
            }
        }
        
        max_len = max(max_len, max(inc[i], dec[i]));
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
        
        cout << solve(nums, n) << endl;
    }
}