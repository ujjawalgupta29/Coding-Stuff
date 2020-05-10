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

int getVal(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }

    else
    {
        return -1;
    }
    
}

bool one_bit_set(int bit_vec)
{
    return ( (bit_vec & (bit_vec - 1)) == 0);
}

bool check(string s)
{
    int bit_vec = 0;
    for(char c : s)
    {
        int val = getVal(c);

        if(val != -1)
        {
            int mask = 1 << val;
            if((bit_vec & mask) == 0)
                bit_vec |= mask;
            else
            {
                bit_vec = bit_vec & (~mask);
            }
            
        }
    }
    return ((bit_vec == 0) || one_bit_set(bit_vec));
}

int main()
{
    //Code
    string s;
    getline(cin, s);
    if(check(s))
        cout << "yes" << endl;
    else
    {
        cout << "no" << endl;
    }
    
    return 0;
}