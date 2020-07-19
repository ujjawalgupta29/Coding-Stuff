#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void reverse(vector<int> &nums, int l, int r)
{
    while(l < r)
    {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

void merge(vector<int> &nums, int l, int m, int r)
{
    int i=l;
    int j=m+1;
    
    while(i <= m && nums[i] >= 0)
        i++;
    
    while(j <= r && nums[j] >= 0)
        j++;
        
    reverse(nums, i, m);
    reverse(nums, m+1, j-1);
    
    reverse(nums, i, j-1);
}

void merge_sort(vector<int> &nums, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        
        merge_sort(nums, l, m);
        merge_sort(nums, m+1, r);
        merge(nums, l, m, r);
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
        
        merge_sort(nums, 0, n-1);
        
        for(int x : nums)
            cout << x << " ";
            
        cout << endl;
    }
}