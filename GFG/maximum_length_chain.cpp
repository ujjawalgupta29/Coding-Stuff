// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool compare(struct val &p1, struct val &p2)
{
    return p1.first < p2.first;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
    // sort(p, p+n, compare);
    
    // vector<int> dp(n,1);
    // int max_len = 1;
    
    // for(int i=1; i<n; i++)
    // {
    //     for(int j=i-1; j>=0; j--)
    //     {
    //         if(p[j].second < p[i].first)
    //         {
    //             dp[i] = max(dp[i], 1+dp[j]);
    //         }
    //     }
        
    //     max_len = max(max_len, dp[i]);
    // }
    
    // return max_len;
    return 0;
}