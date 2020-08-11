#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int len;
        cin >> len;
        
        vector<int> cuts(3);
        for(int i=0; i<3; i++)
            cin >> cuts[i];
        
        vector<int> dp(len+1, 0);
        
        for(int l=1; l<=len; l++)
        {
            for(int i=0; i<3; i++)
            {
                if(l >= cuts[i] && (dp[l - cuts[i]] != 0 ||
                (l - cuts[i]) == 0))
                {
                    dp[l] = max(dp[l], 1 + dp[l - cuts[i]]);
                }
            }
        }
        
        cout << dp[len] << endl;
    }
}