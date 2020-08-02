#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<char> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }

        // for(int i=0; i<n; i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        
        queue<char> q;
        unordered_map<char, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] == 1)
            {
                q.push(nums[i]);
            }
            
            if(!q.size())
            {
                cout << "-1 ";
            }
            
            else
            {
                if(mp[q.front()] > 1)
                {
                    q.pop();
                }
                
                if(q.size())
                    cout << q.front() << " ";
                else
                    cout << "-1 ";
            }
        }
        
        cout << endl;
    }
}