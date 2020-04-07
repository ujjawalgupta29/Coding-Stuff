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

VC get_new_pattern(string pattern)
{
    VC pattern_char;

    if(pattern[0] == 'x')
    {
        return VC(pattern.begin(), pattern.end());
    }

    else
    {
        for(int i=0; i<pattern.size(); i++)
        {
            if(pattern[i] == 'x')
                pattern_char.push_back('y');

            else
            {
                pattern_char.push_back('x');
            }
            
        }
    }
    
    return pattern_char;
}

int get_xy_counts(VC pattern_chars, VI &counts)
{   
    int first = -1;
    
    for(int i=0; i < pattern_chars.size(); i++)
    {
        if(pattern_chars[i] == 'x')
        {
            counts[0]++;
        }
        else
        {
            if(first == -1)
                first = i;
            counts[1]++;
        }
    }
    return first;
}

VS get_xy(VC pattern_chars, string str, int first_y, VI counts)
{
    VS xy(2);
    for(int lenx = 1; lenx < str.length(); lenx++)
    {
        int leny = (str.length() - counts[0]*lenx) / counts[1];

        if(leny <=0 || leny * counts[1] != (str.length() - counts[0]*lenx))
        {
            // cout << "leny = " << leny << endl;
            continue;
        }
        
        else
        {
            // cout << "current len = " << lenx << " " << leny << endl;
            string strx = str.substr(0, lenx);
            string stry = str.substr(first_y*lenx, leny);
            string res;
            // cout << "x = "<<strx << " y = " << stry <<endl;
            for(int i=0; i<pattern_chars.size(); i++)
            {
                res += (pattern_chars[i] == 'x') ? strx : stry;
                // cout<< "query: " << res <<endl;
            }

            if(res == str)
            {
                xy[0] = strx;
                xy[1] = stry;
                return xy;
            }

        }
        
    }

    return xy;
}

int main()
{
    //Code
    string str, pattern;
    cin >> pattern >> str;

    VC pattern_chars = get_new_pattern(pattern);
    VI counts(2, 0);
    int first_y = get_xy_counts(pattern_chars, counts);

    bool switched = false;
    if(pattern[0] != pattern_chars[0])
        switched = 1;

    if(counts[1] != 0)
    {
        VS result(2);
        result = get_xy(pattern_chars, str, first_y, counts);
        if(!switched)
        {
            cout << result[0] << " " << result[1] << endl;
        }

        else
        {
            cout << result[1] << " " << result[0] << endl;
        }
    }
        
    
    else
    {
        int lenx = str.length() / counts[0];
        string strx = str.substr(0, lenx);
        if(!switched)
        {
            cout << strx << "" << endl;
        }

        else
        {
            cout << "" << strx << endl;
        }
    }
    
    return 0;
}