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

VV getLocations(string str1, string str2)
{
    int start = 0;
    VV locations;
    
    while(start < str1.length())
    {
        int found = str1.find(str2, start);
        if(found != string::npos)
        {
            locations.push_back(VI{found, found + (int)str2.length()});
            start = found + 1;
        }

        else 
            break;
    }

    return locations;
}

VV finalLocations(string str1, string str2, VV locations)
{
    int n = locations.size();
    if(n == 0)
        return locations;

    VV final_loc;
    final_loc.push_back(locations[0]);

    ifor(i, 1, n)
    {
        if(locations[i][0] <= final_loc[final_loc.size() - 1][1])
        {
            final_loc[final_loc.size() - 1][1] = locations[i][1];
        }
        else
        {
            final_loc.push_back(locations[i]);
        }
        
    }

    return final_loc;
}

string underscorify(string str1, VV loc)
{
    int stridx = 0;
    int locidx = 0;
    vector<char> final_string;
    int i = 0;
    bool between = false;
    while(stridx < str1.size() && locidx < loc.size())
    {
        if(stridx == loc[locidx][i])
        {
            final_string.push_back('_');
            between = !between;

            if(!between)
            {
                locidx += 1;
            }

            if(i) i = 0;
            else i = 1;
        }

        final_string.push_back(str1[stridx]);
        stridx += 1;
    }
    if(locidx < loc.size())
        final_string.push_back('_');
    while(stridx < str1.size())
    {
        final_string.push_back(str1[stridx]);
        stridx++;
    }
    string res(final_string.begin(), final_string.end());
    return res;
}

int main()
{
    //Code
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    VV locations = getLocations(str1, str2);
    // for(int i=0; i < locations.size(); i++)
    // {
    //     for(int x : locations[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    VV new_loc = finalLocations(str1, str2, locations);
    // for(int i=0; i < new_loc.size(); i++)
    // {
    //     for(int x : new_loc[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    string final_str = underscorify(str1, new_loc);

    cout << final_str << endl;

    return 0;
}

// _test_this is a _testtest_ to see if _testestest_ it works