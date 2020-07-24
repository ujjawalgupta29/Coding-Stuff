#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        
        vector<vector<int>> nums(m, vector<int>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> nums[i][j];
            }
        }
        
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0; i<m; i++)
        {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][n-1]);
        }
        
        int desired = (1 + m*n) / 2;
        
        while(mini <= maxi)
        {
            int mid = (mini + maxi) / 2;
            int counts = 0;
            for(int i=0; i<m; i++)
            {
                counts += upper_bound(nums[i].begin(), nums[i].end(), mid)
                        - nums[i].begin();
            }
            
            if(counts < desired)
                mini = mid + 1;
                
            else
                maxi = mid - 1;
        }
        
        cout << mini << endl;
    }
}