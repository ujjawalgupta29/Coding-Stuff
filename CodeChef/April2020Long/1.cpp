#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef vector<int> VI;

int main()
{
    //Code
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        VI line(n);
        int flag = 1;
        VI pos;
        
        ifor(i, 0, n)
        {
            cin >> line[i];
            if(line[i])
            {
                pos.push_back(i);
            }
        }
        
        ifor(i, 1, pos.size())
        {
            if(pos[i] - pos[i-1] < 6)
            {
                flag = 0;
                break;
            }
        
        }

        if(flag)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}