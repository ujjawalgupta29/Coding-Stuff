#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1e9 + 7;
int dp[1002][802] = {0};

int calculate(int n, int r)
{
    if(n == r)
        return 1;
        
    if(r == 1)
        return n;
        
    if(!dp[n][r])
    {
        dp[n][r] = (calculate(n-1, r) + calculate(n-1, r-1)) % mod;
    }
    
    return dp[n][r];
    
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, r; 
        cin >> n >> r;
        if(n < r)
        {
            cout << "0" << endl;
        }
        else
            cout << calculate(n, r) << endl;
        
    }
}