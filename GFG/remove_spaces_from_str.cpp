#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    int counts = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            counts++;
        }

        else
        {
            s[i-counts] = s[i];
        }
    }

    cout << s.substr(0, s.size()-counts) << endl;
}