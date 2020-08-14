#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<vector<int>> &nums, int n)
{
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int sum1=0,sum2=0,sum3=0;
            if(j-1 >= 0)
            {
                sum1 = nums[i][j] + nums[i-1][j-1];
            }
            
            if(j+1 < n)
            {
                sum2 = nums[i][j] + nums[i-1][j+1];
            }
            
            sum3 = nums[i][j] + nums[i-1][j];
            
            nums[i][j] = max(sum1, max(sum2, sum3));
        }
    }
    
    return *max_element(nums[n-1].begin(), nums[n-1].end());
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<vector<int>> nums(n, vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin >> nums[i][j];
        }
        
        cout << solve(nums, n) << endl;
    }
}