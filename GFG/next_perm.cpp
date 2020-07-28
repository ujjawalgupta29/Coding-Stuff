#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
        
        int i;
        for(i=n-1; i>0; i--)
        {
            if(nums[i] > nums[i-1])
                break;
        }
        
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
        }
        
        else
        {
            int idx1 = i-1;
            // cout << "idx1 = " << idx1 << endl;
            int j;
            for(j=i; j<n; j++)
            {
                if(nums[j] < nums[idx1])
                    break;
            }
            
            int idx2 = j-1;
            // cout << "idx2 = " << idx2 << endl;
            swap(nums[idx1], nums[idx2]);
            
            sort(nums.begin() + idx1 + 1, nums.end());
        }
        
        for(int x : nums)
        {
            cout << x << " ";
        }
        
        cout << endl;
    }
}