#include<bits/stdc++.h>
using namespace std;

#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef vector<int> VI;
long long mod = 1e9 + 7;

int main()
{
    //Code
    int t;
    cin >> t;

    int n;
    while(t--)
    {
        cin >> n;

        vector<long long> nums(n);
        long long profit = 0;

        ifor(i, 0 ,n) cin >> nums[i];
        sort(nums.begin(), nums.end());

        int depre = 0;

        dfor(i, n-1, 0)
        {
            if(nums[i] - depre <= 0)
                break;
            profit = (profit + nums[i]) % mod;
            profit = profit - depre;
            depre++;
        }

        cout<<profit<<endl;
    }


    return 0;
}