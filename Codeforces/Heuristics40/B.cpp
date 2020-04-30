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
    int n,k;
    
    cin >> t;
    
    while(t--)
    {
        cin >> n >> k;
        string res = string(k, '0');
        while(n--)
        {
            string str;
            cin >> str;
            int len = str.size();
            int j = k - len;
            for(int i=0; i < len ; i++)
            {
                if(str[i] == '1')
                {
                    res[j] = '1';
                }
                j++;
            }
        }
        cout << res << endl;
    }
    return 0;
}