#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
        
        int max_len = 0;
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[nums[i]] = 1;
        }
        
        for(int i=0; i<n; i++)
        {
            if(mp[nums[i]-1] == 0)
            {
                int x = nums[i];
                while(mp[x] == 1)
                {
                    x++;
                }
                max_len = max(max_len, x-nums[i]);
            }
        }
        
        cout << max_len << endl;
    }
}