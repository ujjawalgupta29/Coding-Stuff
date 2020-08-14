// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 



int findMaxDiff(int [], int n);

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	cout<<findMaxDiff(a,n)<<endl;
   }
    return 0;
}


// } Driver Code Ends


/*You are required to complete this method */
int findMaxDiff(int nums[], int n)
{
  //Your code here
  stack<int> left, right;
  vector<int> left_small(n, 0), right_small(n, 0);
  
  for(int i=n-1; i>=0; i--)
  {
      while(!left.empty() && nums[left.top()] > nums[i])
      {
          left_small[left.top()] = nums[i];
          left.pop();
      }
      
      left.push(i);
  }
  
  for(int i=0; i<n; i++)
  {
      while(!right.empty() && nums[right.top()] > nums[i])
      {
          right_small[right.top()] = nums[i];
          right.pop();
      }
      
      right.push(i);
  }
  
  int max_diff = INT_MIN;
  
  for(int i=0; i<n; i++)
  {
      max_diff = max(max_diff, abs(right_small[i] - left_small[i]));
  }
  
  return max_diff;
  
  
}