// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/
bool is_k_palin(string str,int k)
{
   int n = str.size(); 
   int i, j, cl; 
   int L[n][n]; 
  
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 

    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    int removals =  str.size() - L[0][n-1];
    return (removals <= k) ? 1 : 0; 
}