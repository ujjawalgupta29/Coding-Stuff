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
        set<int> subarrSums;
        int sum = 0;
        bool flag = 0;
        
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum == 0 || subarrSums.find(sum) != subarrSums.end())
            {
                flag = 1;
                break;
            }
            else
                subarrSums.insert(sum);
        }
        
        if(flag)
            cout << "Yes" << endl;
            
        else
            cout << "No" << endl;
    }
    
    
}