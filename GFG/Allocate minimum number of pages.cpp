#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(vector<ll> &nums, ll x, ll stu)
{
    ll students = 1;
    ll pages = 0;
    for(ll p : nums)
    {
        pages += p;
        if(pages > x)
        {
            students++;
            pages = p;
        }
        if(students > stu)
            return 0;
    }
    
    return students <= stu;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        ll n;
        cin >> n;
        
        vector<ll> nums(n);
        for(ll i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        ll stu;
        cin >> stu;
        
        if(stu > n)
        {
            cout << -1 << endl;
            continue;
        }
        
        long long int l = nums[0];
        long long int r = 0;
        for(ll x : nums)
        {
            l = max(l, (ll)x);
            r += x;
        }
            
        while(l < r)
        {
            ll mid = l + (r - l) / 2;
            
            if(check(nums, mid, stu))
                r = mid;
                
            else
                l = mid + 1;
        }
        
        cout << l << endl;
    }
}