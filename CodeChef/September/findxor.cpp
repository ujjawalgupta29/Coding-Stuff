#include<bits/stdc++.h>
using namespace std;

int solve()
{
    long long n, answer=0;
    cin >> n;

    vector<long long> xorsum;
    long long x;

    for(long long i=1; i<=20; i++)
    {
        cout << 1 << " " << (1ul<<i) << endl;
        cout.flush();
        cin >> x;
        xorsum.push_back(x);
    }

    reverse(xorsum.begin(), xorsum.end());
    long long sum = xorsum[0] - n*(1ul<<20);

    for(long long i=1; i<xorsum.size(); i++)
    {
        if(xorsum[i] >= sum)
        {
            xorsum[i] = ((n-(xorsum[i] - sum) / (1ul<<(xorsum.size()-i)))/2);
        }
        else
        {
            xorsum[i] = (n+(sum - xorsum[i]) / (1ul<<(xorsum.size()-i)))/2;
        }
        
    }

    for(int i=1; i<xorsum.size(); i++)
    if(xorsum[i]%2 != 0)
    answer += 1ul << (xorsum.size()-1);
    if(sum%2 != 0)
    answer++;

    cout << 2 << " " << answer << endl;
    cout.flush();

    int result;
    cin >> result;

    return result;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        if(solve() == -1)
        {
            break;
        }
        // cout << endl;
        cout.flush();
    }
    return 0;
}