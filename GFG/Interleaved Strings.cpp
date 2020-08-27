// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/*You are required to complete this method */
int dp[101][101][101];
bool solve(string A, string B, string C, int i, int j, int k, int a, 
            int b, int c)
{
    if(k == c && i == a && j == b)
        return 1;
        
    if(k == c)
        return 0;
        
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    
    return dp[i][j][k] = ((i < a && A[i] == C[k] && solve(A, B, C, i+1, j, k+1, a, b, c)) ||
            (j < b && B[j] == C[k] && solve(A, B, C, i, j+1, k+1, a, b, c)));   
        
}

bool isInterleave(string A, string B, string C) 
{
    //Your code here
    int a = A.size();
    int b = B.size();
    int c = C.size();
    memset(dp, -1, sizeof(dp));
    return solve(A, B, C, 0, 0, 0, a, b, c);
}
