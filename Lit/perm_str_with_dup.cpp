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

void permute(map<char, int> &freq, vector<string> &res, string temp, int len)
{
    if(len == 0)
    {
        res.push_back(temp);
        return;
    }

    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        char c = it->first;
        int count = freq[c];

        if(count > 0)
        {
            freq[c]--;
            permute(freq, res, temp + c, len - 1);
            freq[c]++;
        }
    }
}

int main()
{
    //Code
    string s;
    cin >> s;
    map<char, int> freq;
    for(char c : s)
        freq[c]++;
    vector<string> res;
    permute(freq, res, "", s.length());

    for(string temp : res)
        cout << temp << " ";
    cout << endl;
    return 0;
}