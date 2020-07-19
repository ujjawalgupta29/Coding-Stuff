#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
     
    while(t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        
        vector<int> nums1(n1), nums2(n2), nums3(n3);
        
        for(int i=0; i<n1; i++)
            cin >> nums1[i];
            
        for(int i=0; i<n2; i++)
            cin >> nums2[i];
            
        for(int i=0; i<n3; i++)
            cin >> nums3[i];
        
        int i=0, j=0, k=0;
        
        vector<int> res;
        
        for(; i<n1 && j < n2 && k < n3; )
        {
            if(nums1[i] == nums2[j] && nums2[j] == nums3[k])
            {
                if(!res.size() || res.back() != nums1[i])
                    res.push_back(nums1[i]);
                i++;
                j++;
                k++;
            }
            
            else if(nums1[i] <= nums2[j] && nums1[i] <= nums3[k])
            {
                i++;
            }
            
            else if(nums1[i] >= nums2[j] && nums2[j] <= nums3[k])
            {
                j++;
            }
            
            else if(nums3[k] <= nums2[j] && nums1[i] >= nums3[k])
            {
                k++;
            }
        }
        
        if(!res.size())
            res.push_back(-1);
        
        for(int x : res)
            cout << x << " ";
            
        cout << endl;
    }
}