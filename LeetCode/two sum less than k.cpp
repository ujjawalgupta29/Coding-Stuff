// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// arr[]: Input array
// n: Number of elements in the array
// k: Find a pair with sum less than k
pair<int,int> Max_Sum(int arr[], int n, int k)
{
    // return the pair
    sort(arr, arr+n);
    int idx1=-1, idx2=-1;
    int l=0, r=n-1;
    int max_sum = INT_MIN;
    
    while(l < r)
    {
        int sum = arr[l] + arr[r];
        if(sum >= k)
            r--;
            
        else
        {
            if(sum > max_sum && sum < k)
            {
                max_sum = sum;
                idx1 = l;
                idx2 = r;
            }
            l++;
        }
    }
    
    if(idx1 == -1)
        return {0, 0};
    
    return {arr[idx1], arr[idx2]};
}

