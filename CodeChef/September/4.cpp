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

        int a[n+1];
        for(int i=1; i<=n; i++)
            cin >> a[i];

        int m=1;
        int ans = 0;

        vector<int> v;

        for(int i=1; i<=n; i++)
        {
            int temp = a[i];
            temp += m;
            v.push_back(temp);
            m++;
            if(m == n-i)
                break;
        }

        ans = v.size();
        cout << ans << endl;
    }
}