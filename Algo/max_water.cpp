#include<bits/stdc++.h>
using namespace std;

#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef vector<int> VI;

int main()
{
    //Code
    int n;
    cin >> n;
    v(n);

    ifor(i, 0, n) cin >> v[i];

    VI water(n);
    int sum = 0;
    int leftmax = 0;

    ifor(i, 0, n)
    {
        water[i] = leftmax;
        leftmax = max(leftmax, v[i]);
    }

    int rightmax = 0;
    dfor(i, n-1, 0)
    {
        water[i] = min(water[i], rightmax);
        rightmax = max(rightmax, v[i]);
        water[i] = (v[i] <= water[i]) ? (water[i] - v[i]) : 0;
        sum += water[i];
    }

    cout<<" Max Water:- "<<sum<<endl;

    return 0;
}