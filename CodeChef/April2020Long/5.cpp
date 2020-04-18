#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

ll findSubarraySum(vector<ll> &arr, ll sum) 
{ 
    unordered_map<ll, ll> prevSum; 
    ll n = arr.size();
  
    ll res = 0; 
  
    ll currsum = 0; 
  
    for (ll i = 0; i < n; i++) { 
  
        currsum += arr[i]; 

        if (currsum == sum)  
            res++;         

        if (prevSum.find(currsum - sum) != prevSum.end())  
            res += (prevSum[currsum - sum]); 

        prevSum[currsum]++; 
    } 
  
    return res; 
} 

int main()
{
    //Code
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
            nums[i] = abs(nums[i]);

            if(nums[i] % 2 != 0)
                nums[i] = 0;
            else if(nums[i] % 4 == 0)
                nums[i] = 2;
            else
            {
                nums[i] = 1;
            }
        }

        ll total = (n * (n+1)) / 2;

        cout << total - findSubarraySum(nums, 1) << endl;
    }
    return 0;
}