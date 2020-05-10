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

int search(VS str, string target, int l, int r)
{
    if(l > r)
        return -1;
    
    int mid = (l + r) / 2;
    if(str[mid] == target)
        return mid;

    else if(str[mid] == "")
    {
        l = search(str, target, l, mid-1);
        if(l >= 0)
            return l;
        r = search(str, target, mid + 1, r);
        return r;
    }

    else if(str[mid] < target)
        l = mid + 1;

    else if(str[mid] > target)
        r = mid - 1;

    return -1;
}

int main()
{
    //Code
    vector<string> str{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string target;
    // cin >> target;
    getline(cin, target); //so we can give empty string from terminal

    cout << search(str, target, 0, str.size()-1);

    return 0;
}