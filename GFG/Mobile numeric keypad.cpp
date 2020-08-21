#include<bits/stdc++.h>
using namespace std;
#define ll long long int

long long int dp[10][31];
vector<vector<int>> pad = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};

long long int solve(int i, int j, int n)
{
    if(i < 0 || j < 0 || i >= 4 || j >= 3 || pad[i][j] == -1)
        return 0;
        
    if(n == 0)
        return 1;
        
    int number = pad[i][j];
    
    if(dp[number][n] != -1)
        return dp[number][n];
        
    long long int res = 0;
    
    res += solve(i-1, j, n-1) + solve(i+1, j, n-1)
            + solve(i, j-1, n-1) + solve(i, j+1, n-1) + solve(i, j, n-1);
    
    return dp[number][n] = res;
    
}

int main()
{
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    
    while(t--)
    {
        int n;
        cin >> n;
        
        long long int ans = 0;
        
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
            {
                ans += solve(i, j, n-1);
            }
        }
        cout << ans << endl;
    }
}