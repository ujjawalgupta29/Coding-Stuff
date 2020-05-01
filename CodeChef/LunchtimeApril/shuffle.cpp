#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    //Code
    int t;
    cin >> t;

    int n, k;
    while(t--)
    {
        cin >> n >> k;
        VI nums(n);
        ifor(i, 0, n) cin >> nums[i];

        VI sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        VI visited(n, 0);
        for(int i = 0; i + k < n; i++ )
        {
            if(!visited[i])
            {
                VI temp;
                for(int j = i; j < n; j += k)
                {
                    visited[j] = 1;
                    temp.push_back(nums[j]);
                }
                sort(temp.begin(), temp.end());
                
                int idx = 0;
                for(int j = i; j < n; j += k)
                {
                    nums[j] = temp[idx];
                    idx++;
                }
            }
        }

        // for(int x : nums) cout << x << " ";
        // cout << endl;

        int flag = 1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] != sorted[i])
            {
                flag = 0;
                break;
            }
        }
        cout << ( (flag) ? "yes" : "no" ) << endl; 
    }
    return 0;
}