#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        
        vector<int> nums1(m),nums2(n);
        for(int i=0; i<m; i++)
        {
            cin >> nums1[i];
        }
        for(int i=0; i<n; i++)
        {
            cin >> nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int idx1=0, idx2=0;
        
        while(idx1 < m && idx2 < n)
        {
            if(nums1[idx1] == nums2[idx2])
            {
                idx1++;
                idx2++;
            }
            
            else if(nums1[idx1] < nums2[idx2])
            {
                idx1++;
            }
            
            else
            {
                break;
            }
        }
        
        if(idx2 == n)
            cout << "Yes" << endl;
            
        else
            cout << "No" << endl;
    }
}