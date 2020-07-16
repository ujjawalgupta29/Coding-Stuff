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
            
        int k;
        cin >> k;
        
        nth_element(nums.begin(), nums.begin()+k-1, nums.end());
        
        cout << nums[k-1] << endl;
        
    }
}