#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void heapify(vector<int> &nums, int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && nums[left] > nums[largest])
        largest = left;
        
    if(right < n && nums[right] > nums[largest])
        largest = right;
        
    if(largest != i)
    {
        swap(nums[largest], nums[i]);
        heapify(nums, n, largest);
    }
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        
        vector<int> nums1(n1);
        for(int i=0; i<n1; i++)
        {
            cin >> nums1[i];
        }
        
        vector<int> nums2(n2);
        for(int i=0; i<n2; i++)
        {
            cin >> nums2[i];
        }
        
        vector<int> nums;
        for(int i=0; i<n1; i++)
            nums.push_back(nums1[i]);
            
        for(int i=0; i<n2; i++)
            nums.push_back(nums2[i]);
            
        int n = n1+n2;
        
        for(int i=n/2-1; i>=0; i--)
        {
            heapify(nums, n, i);
        }
        
        for(int x : nums)
            cout << x << " ";
            
        cout << endl;
    }
}