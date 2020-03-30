#include<bits/stdc++.h>
using namespace std;

vector<int> getLongestPalSubstr(string str, int left, int right)
{
    vector<int>result(2);

    while(left >= 0 && right < str.length())
    {
        if(str[left] == str[right])
        {
            left--;
            right++;
        }

        else
        {
            break;
        }
        
    }

    result[0] = left+1;
    result[1] = right;

    return result;
}

int main()
{
    string str;
    cin >> str;

    vector<int> longest(2);
    longest[0] = 0, longest[1] = 1;

    for(int i=1; i<str.length(); i++)
    {
        vector<int> odd = getLongestPalSubstr(str, i-1, i+1);
        vector<int> even = getLongestPalSubstr(str, i-1, i);

        vector<int> temp_max = ( (odd[1] - odd[0]) > (even[1] - even[0]) ) ? odd : even;
        longest = ( (longest[1] - longest[0]) > (temp_max[1] - temp_max[0]) ) ? longest : temp_max;
    }

    cout << str.substr(longest[0], longest[1] - longest[0])<<endl;
}