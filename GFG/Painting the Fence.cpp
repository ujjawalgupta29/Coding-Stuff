#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        
        vector<long> dp(n+1, 0);
        
        if(n == 1)
        {
            cout << k << endl;
        }
        
        else if(n == 2)
        {
            cout << k*k << endl;
        }
        
        else
        {
            dp[1] = k;
            dp[2] = k*k;
            
            for(int i=3; i<=n; i++)
            {
                dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
            }   
            
            cout << dp[n] << endl;
        }
    }
}