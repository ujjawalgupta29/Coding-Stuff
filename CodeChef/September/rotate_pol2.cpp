#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
ll maxi = 2000000000;

void generate(vector<vector<ll>> &coordi, ll x, ll y, ll opp)
{
    if(opp)
    {
        ll prev = 0;
        while(abs(x) <= maxi)
        {
            coordi.push_back(vector<ll>{x, y});

            if(abs(x) <= maxi/2)
            {
                x *= 2;
                coordi.push_back(vector<ll>{(prev+x)/2, y});

                prev = x;
            }
            else
            {
                break;
            }
            
        }
    }

    else
    {   
        ll prev = y;
        while(abs(y) <= maxi)
        {
            coordi.push_back(vector<ll>{x, y});

            if(abs(y) <= maxi/2)
            {
                y *= 2;
                coordi.push_back(vector<ll>{x, (y+prev)/2});
                prev = y;
            }
            else
            {
                break;
            }
            
        }
    }
    
}

bool check(vector<ll> &arr)
{
    int n = arr.size();
    if(n == 0)
        return true;
    
    ll first = arr[0];

    for(ll i=1; i<n; i++)
    {
        if(arr[i] != first + i)
            return false;
    }

    return true;
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        vector<vector<ll>> points(n, vector<ll>(2, 0));
        for(int i=0; i<n; i++)
            cin >> points[i][0] >> points[i][1];

        vector<vector<ll>> v(n, vector<ll>(2, 0));

        for(int i=0; i<n-1; i++)
        {
            v[i][0] = points[i+1][0] - points[i][0];
            v[i][1] = points[i+1][1] - points[i][1];
        }

        v[n-1][0] = points[0][0] - points[n-1][0];
        v[n-1][1] = points[0][1] - points[n-1][1];

        vector<vector<ll>> coordi = {
            {0, maxi}, {maxi, 0},
            {-maxi, 0}, {0, -maxi},

            {maxi, -maxi},{-maxi, maxi},
            {maxi, maxi}, {-maxi, -maxi}
        };

        generate(coordi, 1, maxi, 1);
        generate(coordi, maxi, 1, 0);

        generate(coordi, maxi, -1, 0);
        generate(coordi, 1, -maxi, 1);

        generate(coordi, -1, -maxi, 1);
        generate(coordi, -maxi, -1, 0);

        generate(coordi, -maxi, 1, 0);
        generate(coordi, -1, maxi, 1);

        
        for(ll i=1; i<n; i+=10)
        {
            coordi.push_back(v[i]);
        }

        int xv=0, yv=0;

        for(ll i=0; i<coordi.size(); i++)
        {
            vector<ll> positive;
            vector<ll> negative;

            bool flag = 1;

            for(ll j=0; j<n; j++)
            {
                ll temp = coordi[i][0]*v[j][0] + coordi[i][1]*v[j][1];

                if(temp > 0)
                {
                    positive.push_back(j);
                }

                else if(temp == 0)
                {
                    flag = 0;
                    break;
                }

                else
                {
                    negative.push_back(j);
                }
                
            }

            if( flag && ( check(positive) || check(negative) ) )
            {
                xv = coordi[i][0];
                yv = coordi[i][1];
                break;
            }
        }

        cout << xv << " " << yv << endl;
    }
}