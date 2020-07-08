// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    int candidate = 0;
    for(int i=1; i<n; i++)
    {
        if(M[candidate][i])
        {
            candidate = i;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(i != candidate && (M[candidate][i] || M[i][candidate] == 0) )
        {
            return -1;
        }
    }
    
    return candidate;
}