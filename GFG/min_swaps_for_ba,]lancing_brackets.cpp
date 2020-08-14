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
        
        string s;
        cin >> s;
        
        vector<int> pos;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '[')
                pos.push_back(i);
        }
        
        int counts = 0;
        int res = 0;
        int p = 0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == '[')
            {
                counts++;
                p++;
            }
            
            else if(s[i] == ']')
                counts--;
                
            if(counts < 0)
            {
                res += pos[p] - i;
                swap(s[i], s[pos[p]]);
                p++;
                counts = 1;
            }
        }
        
        cout << res << endl;
    }
}