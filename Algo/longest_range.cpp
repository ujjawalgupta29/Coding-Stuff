#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        mp[v[i]] = 1;
    }

    int left_range, right_range, length = 0;

    for(int i=0; i<n; i++)
    {
        mp[v[i]] = 0;
        int temp1 = v[i]-1, temp2 = v[i]+1;

        while(1)
        {
            if(mp[temp1])
            {
                mp[temp1] = 0;
                temp1--;
                continue;
            }
            else
            {
                break;
            }
            
        }

        while(1)
        {
            if(mp[temp2])
            {
                mp[temp2] = 0;
                temp2++;
                continue;
            }   
            else
            {
                break;
            }
            
        }

        temp1++;
        temp2--;

        if(temp2 - temp1 + 1 > length)
        {
            length = temp2 - temp1 + 1;
            left_range = temp1;
            right_range = temp2;
        }
    }
    cout<<left_range<<" "<<right_range<<endl;
}