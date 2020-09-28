#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int temp;

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++)
        {
            cin >> temp;
            if(temp != 0)
                mp[temp] = 1;
        }

        cout << mp.size() << endl;
    }
}