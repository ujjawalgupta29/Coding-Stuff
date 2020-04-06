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

void longest(string str, VI &index)
{
    unordered_map<char, int> mp;
    int start = 0;

    ifor(i, 0, str.size())
    {
        if(mp.find(str[i]) != mp.end())
        {
            start = max(start, mp[str[i]] + 1);
        }
        
        if(index[1] - index[0] + 1 < i + 1 - start)
        {
            index[0] = start;
            index[1] = i;
        }

        mp[str[i]] = i;
        
    }
}

int main()
{
    //Code
    string str;
    cin >> str;

    VI index(2, 0);
    longest(str, index);

    cout << str.substr(index[0], index[1] - index[0] + 1);
    return 0;
}