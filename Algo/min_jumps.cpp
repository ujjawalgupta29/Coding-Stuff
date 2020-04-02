#include<bits/stdc++.h>
using namespace std;

#define v(n) vector<int> v(n)
// #define fr(i) for(int i=0; i<n; i++)
#define for(i, a, b) for(int i=a; i<b; i++)

int main()
{
    int n;
    cin >> n;
    v(n);
    int min_jumps = 0;

    for(i, 0, n)
        cin >> v[i];
    
    if(n == 1)
    {
        cout<<0<<endl;
        return 0;
    }


    int maxreach = v[0];
    int steps = v[0];
    int jumps = 0;

    for(i, 1, n)
    {
        maxreach = max(maxreach, v[i] + i);
        steps--;

        if(steps == 0)
        {
            steps = maxreach - i;
            jumps++;
        }
    }

    cout<<"Jumps = "<<jumps+1<<endl;

    return 0;
}