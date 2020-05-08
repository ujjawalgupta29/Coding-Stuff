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

bool check_diff(string s1, string s2)
{
    if(s1.size() > s2.size())
        swap(s1, s2);

    int len1 = s1.size();
    int len2 = s2.size();

    if(len2 - len1 > 1)
        return 0;

    int idx1=0, idx2=0;
    bool found = 0;

    while(idx1 < len1 && idx2 < len2)
    {
        if(s1[idx1] != s2[idx2])
        {
            if(found)
                return 0;
            found = true;
            if(len1 == len2)
                idx1++;
        }
        else
        {
            idx1++;
        }
        idx2++;
    }

    return true;
}

int main()
{
    //Code
    string s1, s2;
    cin >> s1 >> s2;
    if(check_diff(s1, s2))
        cout << "yes";
    else
    {
        cout << "no";
    }

    cout <<endl;
    
    return 0;
}