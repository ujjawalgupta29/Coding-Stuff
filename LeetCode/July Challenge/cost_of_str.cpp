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

vector<string> mp{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
                "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

string ans;

void solve(vector<int> &costs, int w, string temp)
{
    if(w == 0)
    {
        ans = temp;
        return;
    }

    for(int i=25; i>=0; i--)
    {
        if(w - costs[i] >= 0)
        {
            temp += mp[i];
            solve(costs, w - costs[i], temp);
            if(ans != "")
                return;
            temp.pop_back();
        }
    }
}

int main()
{
    vector<int> costs(26);

    for(int i=0; i<26; i++)
        cin >> costs[i];

    int w;
    cin >> w;

    solve(costs, w, "");
    cout << ans << endl;
}

/*
252 888 578 746 295 884 198 665 503 868 942 506 718 498 727 338 43 768 783 312 369 712 230 106 102 554
6674
*/