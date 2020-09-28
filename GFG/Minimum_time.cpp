#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int n, int cost_i, int cost_d, int cost_c)
{
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    dp[1] = cost_i;
    
    for(int i=2; i<=n; i++)
    {
        if(i%2)
        {
            dp[i] = min(dp[i-1] + cost_i,
                    dp[(i+1)/2] + cost_c + cost_d);
        }
        else
        {
            dp[i] = min(dp[i-1] + cost_i,
                    dp[i/2] + cost_c);
        }
    }
    
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int cost_i, cost_d, cost_c;
        cin >> cost_i >> cost_d >> cost_c;
        
        cout << solve(n, cost_i, cost_d, cost_c) << endl;
    }
}

//O(n^2)



#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int n, int cost_i, int cost_d, int cost_c)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = cost_i;
    
    for(int i=1; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            int temp = (2*j - i + 1) ;
            if(temp >= 0)
            {
                temp *= cost_d;
                temp += cost_c;
            }
            else
                temp = INT_MAX;
                
            dp[i] = min(dp[i], dp[j] + 
                    min((i-j)*cost_i, temp) );
        }
    }
    
    // for(int x : dp)
    //     cout << x << " ";
    // cout << endl;
    
    return dp[n-1];
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int cost_i, cost_d, cost_c;
        cin >> cost_i >> cost_d >> cost_c;
        
        cout << solve(n, cost_i, cost_d, cost_c) << endl;
    }
}