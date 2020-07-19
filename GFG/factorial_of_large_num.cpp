#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void multiply(vector<int> &res, int n, int &sz)
{
    int carry = 0;
    for(int i=0; i<sz; i++)
    {
        int val = n * res[i] + carry;
        res[i] = val % 10;
        carry = val / 10;
    }
    
    while(carry)
    {
        res[sz] = carry % 10;
        carry = carry/10;
        sz++;
    }
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
    
        vector<int> res(100000);
        res[0] = 1;
        int res_size = 1;
        
        for(int i=2; i<=n; i++)
        {
            multiply(res, i, res_size);
        }
        
        for(int i=res_size - 1; i>=0; i--)
            cout << res[i];
            
        cout << endl;
    }
}