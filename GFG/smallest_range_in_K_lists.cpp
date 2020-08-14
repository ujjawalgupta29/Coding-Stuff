// { Driver Code Starts
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

void findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}

// } Driver Code Ends


// you are required to complete this function 
// function should print the required range
#include <queue>
void findSmallestRange(int arr[][N], int n, int k)
{
      //code here
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      
      int max_ele = INT_MIN;
      
      for(int i=0; i<k; i++)
      {
          pq.push({arr[i][0], i});
          max_ele = max(max_ele, arr[i][0]);
      }
      
      vector<int> curr_idx(k, 0);
      int smallest_range = INT_MAX;
      int start = 0, end = INT_MAX;
      
      for(int i=0; i<n*k; i++)
      {
          int top_ele = pq.top().first;
          int arr_idx = pq.top().second;
          pq.pop();
          
          if(smallest_range > max_ele - top_ele)
          {
              smallest_range = max_ele - top_ele;
              start = top_ele;
              end = max_ele;
          }
          
          if(curr_idx[arr_idx] < n-1)
          {
             curr_idx[arr_idx]++;
             pq.push({arr[arr_idx][curr_idx[arr_idx]] ,arr_idx});
             max_ele = max(max_ele, arr[arr_idx][curr_idx[arr_idx]]);
          }
          else
            break;
      }
      
      cout << start << " " << end << endl;
}