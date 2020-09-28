#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int solve(string s)
{
    vector<int> freq(26, 0);
    // int a=0, b=0, c=0;
    int counts = 0;
    int res = 0;
    int start=0, e=0;
    int len = s.size();

    while(e < len)
    {
        freq[s[e]-'a']++;
        if((s[e] == 'a' || s[e] == 'b' || s[e] == 'c') && freq[s[e]-'a'] == 1)
        {
            counts++;
        }

        while(counts == 3)
        {
            cout << "enetered at index e = " << e << endl;
            res += len-e;
            freq[s[start]-'a']--;
            if(freq[s[start]-'a'] == 0 && (s[start] == 'a' || s[start] == 'b' || s[start] == 'c'))
                counts--;

            start++;
        }
        e++;
    }
    
    return res;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
}