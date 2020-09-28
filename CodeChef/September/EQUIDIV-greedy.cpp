#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;

    int sum = n * (n+1) * (2*n+1) / 6;

    vector<int> taken(n, 0);

    cout << "sum = " << sum << endl;
    int need = sum / 2;
    if(sum%2 != 0)
        need++;
    cout << "need = " << need << endl;

    int sum1=0;

    for(int i=n; i>0; i--)
    {
        if(sum1 + i*i <= need)
        {
            sum1 += i*i;
            taken[i-1] = 1;
        }
    }

    for(int x : taken)
        cout << x;
}