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

        int counts = 0;
        int curr_end = 0;
        
        int dest = 0;
        for(int src = 0; src <= dest && src < n; src++)
        {
            dest = max(dest, src + nums[src]);
                
            if(src == curr_end && src < n-1)
            {
                counts++;
                curr_end = dest;
            }
        }
        
        if(dest >= nums.size() - 1)
            cout << counts << endl;
            
        else
            cout << -1 << endl;
    }
}