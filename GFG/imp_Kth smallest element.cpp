#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int partition(vector<int> &nums, int l ,int r, int pivotIdx)
{
    int left = l;
    int pivotValue = nums[pivotIdx];
    
    swap(nums[pivotIdx], nums[r]);
    
    for(int i=l; i<r; i++)
    {
        if(nums[i] < pivotValue)
        {
            swap(nums[i], nums[left]);
            left++;
        }
    }
    
    swap(nums[left], nums[r]);
    
    return left;
}

int qselect(vector<int> &nums, int l, int r, int reqIdx)
{
    if(l <= r)
    {
        int pivotIdx = l + rand() % (r-l+1);
        int pidx = partition(nums, l, r, pivotIdx);
        
        if(pidx == reqIdx)
            return nums[reqIdx];
            
        else if(reqIdx < pidx)
            return qselect(nums, l, pidx-1, reqIdx);
            
        else
            return qselect(nums, pidx+1, r, reqIdx);
    }
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
            
        int k;
        cin >> k;
        
        cout << qselect(nums, 0, n-1, k-1) << endl;
        
    }
}