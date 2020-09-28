// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends


/*You are required to complete this method*/
int wildCard(string pat,string text)
{
    int len_p = pat.size();
    int len_t = text.size();
    
    vector<vector<bool>> dp(len_t + 1, vector<bool>(len_p + 1, 0));
    dp[0][0] = 1;
    
    for(int i=1; i<=len_p; i++)
    {
        if(pat[i-1] == '*')
            dp[0][i] = 1;
        else
            break;
    }
    
    for(int i=1; i<=len_t; i++)
    {
        for(int j=1; j<=len_p; j++)
        {
            if(pat[j-1] == '*')
            {
                if(dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1])
                    dp[i][j] = 1;
            }
            
            else if(pat[j-1] == '?')
            {
                if(dp[i-1][j-1])
                    dp[i][j] = 1;
            }
            
            else
            {
                if(text[i-1] == pat[j-1])
                {
                    if(dp[i-1][j-1])
                        dp[i][j] = 1;
                }
            }
        }
    }
    return dp[len_t][len_p];    
}