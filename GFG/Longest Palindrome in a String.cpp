#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        string s;
        cin >> s;
        
        int len = s.size();
        
        vector<vector<bool>> dp(len, vector<bool>(len, 0));
        int max_len = 1;
        int idx1=0,idx2=0;
        //lenght=1
        for(int i=0; i<len; i++)
        {
            dp[i][i] = 1;
        }
        //length=2
        for(int i=0; i<len-1; i++)
        {
            dp[i][i+1] = (s[i] == s[i+1]);
            if(max_len < 2 && dp[i][i+1])
            {
                idx1=i;
                idx2=i+1;
                max_len = 2;
            }
        }
        //rem len
        for(int l=3; l<=len; l++)
        {
            for(int start=0; start<=len-l; start++)
            {
                // cout << start << " " << start+l-1 << endl;
                dp[start][start+l-1] = (s[start] == s[start+l-1]) &&
                                        dp[start+1][start+l-2];
                
                if(max_len < l && dp[start][start+l-1])
                {
                    max_len = l;
                    idx1 = start;
                    idx2 = start+l-1;
                }
            }
        }
        
        // for(int i=0; i<len; i++)
        // {
        //     for(int j=0; j<len; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        cout << s.substr(idx1, idx2-idx1+1) << endl;
        
    }
}