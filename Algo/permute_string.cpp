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

void permute(string s, int i, set<string> &res)
{
    if(i == s.size())
        res.insert(s);

    for(int j=i; j<s.size(); j++)
    {
        swap(s[j], s[i]);
        permute(s, i+1, res);
        swap(s[j], s[i]);
    }
}

int main()
{
    //Code
    string s;
    cin >> s;
    set<string> res;
    permute(s, 0, res);
    for(auto it : res)
        cout << it << endl;
    return 0;
}