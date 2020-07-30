#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long n;
        cin >> n;
        
        vector<long> nums(n);
        for(long i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        vector<long> res(n, -1);
        
        stack<long> indexes;
        
        for(long i=0; i<n; i++)
        {
            while(!indexes.empty() && nums[indexes.top()] < nums[i])
            {
                res[indexes.top()] = nums[i];
                indexes.pop();
            }
            indexes.push(i);
        }
        
        for(long x : res)
        {
            cout << x << " ";
        }
        
        cout << endl;
    }
}