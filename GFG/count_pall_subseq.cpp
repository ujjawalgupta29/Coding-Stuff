// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;
 
// Function return the total palindromic subsequence
int countPS(string str);
 
// Driver program
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}// } Driver Code Ends

#include<bits/stdc++.h>
/*You are required to complete below method */

int countPS(string s)
{
   //Your code here
   int n = s.size();
   vector<vector<long long int>> dp(n+1, vector<long long int>(n+1, 0));
   
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    
    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<=n-l; i++)
        {
            int j = i + l -1;
            
            if(s[j] == s[i])
                dp[i][j] = dp[i][j-1] + 1 + dp[i+1][j];
            
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
    }
    
    return dp[0][n-1];
}
 