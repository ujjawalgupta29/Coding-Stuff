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

        vector<int> v(n);

        for(int i=0; i<n; i++)
            cin >> v[i];

        vector<int> big(n,0);
        vector<int> small(n,0);

        stack<int> b;
        stack<int> s;

        for(int i=0; i<n; i++)
        {
            while(!b.empty() && b.top() <= v[i])
            {
                b.pop();
            }
            big[i] = b.size();
            b.push(v[i]);

        }

        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && s.top() >= v[i])
            {
                s.pop();
            }
            small[i] = big[i] + s.size() + 1;
            s.push(v[i]);
        }

        sort(small.begin(), small.end());

        cout << small[0] << " " << small[n-1] << endl;
    }
}   