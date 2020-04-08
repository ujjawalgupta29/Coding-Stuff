#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void build_prefix_array(string substr, VI &prefix)
{
    int i = 1;
    int j = 0;
    int n =substr.length();

    while(i < n)
    {
        if(substr[i] == substr[j])
        {
            prefix[i] = j;
            i++;
            j++;
        }

        else if(j > 0)
            j = prefix[j-1] + 1;

        else
        {
            i++;
        }
        
    }
}

int match(string str, string substr, VI prefix)
{
    int i = 0;
    int j = 0;
    int n = str.length();

    // for(int x : prefix) cout << x << " ";
    // cout << endl;

    while( i + substr.length() - j <= n)
    {
        if(str[i] == substr[j])
        {
            if(j == substr.length() - 1)
                return i - j;

            i++;
            j++;
        }

        else if( j > 0)
        {
            j = prefix[j-1] + 1;
        }

        else
        {
            i++;
        }
        
    }

    return -1;
}

int main()
{
    //Code
    string str, substr;
    cin >> str >> substr;
    VI prefix(substr.length(), -1);

    build_prefix_array(substr, prefix); 
    cout << "Found at index - " << match(str, substr, prefix) << endl;

    return 0;
}