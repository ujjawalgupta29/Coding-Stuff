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


/*You are required to complete below method */

#include<bits/stdc++.h>
int counts(vector<vector<int>> &dp, string s, int i, int j, int len)
{
    if(i > len || j< 0)
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(abs(i-j)==1) 
    { 
        if(s[i] == s[j]) 
            return dp[i][j] = 3; 
        else 
            return dp[i][j] = 2; 
    } 
        
    if(i == j)
    {
        return dp[i][j] = 1;
    }
    
    else if(s[i] == s[j])
    {
        return dp[i][j] = 1 + counts(dp, s, i+1, j, len) + counts(dp, s, i, j-1, len);
    }
    
    else
    {
        return dp[i][j] = - counts(dp, s, i+1, j-1, len) +
                counts(dp, s, i+1, j, len) + counts(dp, s, i, j-1, len);
    }
}

int countPS(string str)
{
   //Your code here
   vector<vector<int>> dp(1005, vector<int>(1005, -1));
   int n = str.size();
   return counts(dp, str, 0, n-1, n-1);
}
 