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

        if(n%4 == 0)
        {
            cout << (n/4 + 1) << endl;
        }

        else if(n%4 == 3)
        {
            cout << ((n+1)/4 + 1) << endl;
        }

        else 
            cout << 0 << endl;
    }
}