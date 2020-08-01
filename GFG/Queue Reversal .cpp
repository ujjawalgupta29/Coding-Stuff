// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<long long int> rev(queue<long long int> q);
int main()
{
    long long int test;
    cin>>test; 
    while(test--)
    {
    queue<long long int> q; 
    long long int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<long long int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

void reverse(queue<long long int> &q)
{
    if(q.empty())
        return;
        
    int top = q.front();
    q.pop();
    
    reverse(q);
    
    q.push(top);
}

queue<long long int> rev(queue<long long int> q)
{
    // add code here.
    reverse(q);
    return q;
}