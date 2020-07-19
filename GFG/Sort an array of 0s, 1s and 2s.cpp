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
        
       int zero=0, one=0, two=n-1;
       
       while(one <= two)
       {
            if(nums[one] == 0)
            {
                swap(nums[zero], nums[one]);
                zero++;
                one++;
            }
            
           else if(nums[one] == 1)
                one++;  
                
            else
            {
                swap(nums[one], nums[two]);
                two--;
            }
       }
        
        for(int x : nums)
            cout << x << " ";
            
        cout << endl;
    }
}