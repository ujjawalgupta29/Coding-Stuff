#include<bits/stdc++.h>
using namespace std;
#define ll long long int

long mod = 1e9 + 7;
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
        
        long overall_max = INT_MIN;
        
        long maxi = 1, mini = 1;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] < 0)
                swap(maxi, mini);
                
            maxi = max((maxi*nums[i])%mod, (long)nums[i]);
            mini = min((mini*nums[i])%mod, (long)nums[i]);
            
            overall_max = max(overall_max, maxi);
        }

        cout << overall_max << endl;
    }
}