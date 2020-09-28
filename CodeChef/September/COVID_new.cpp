#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void create_timings(ll players, vector<vector<ll>> timings[],  vector<ll> &velocity)
{
    for(ll i=0; i<players; i++)
    {
        for(ll j=0; j<i; j++)
        {
            if(velocity[j] > velocity[i])
            {
                ll up = i-j;
                ll down = velocity[j] - velocity[i];
                timings[i].push_back({j, up, down});
            }
        }

        for(ll j=i+1; j<players; j++)
        {
            if(velocity[j] < velocity[i])
            {
                ll up = j-i;
                ll down = velocity[i] - velocity[j];
                timings[i].push_back({j, up, down});
            }
        }
    }
}

void check_infected(vector<int> &infected, vector<vector<ll>> timings[], ll player, double start_time)
{
    if(!infected[player])
    {
        infected[player] = 1;

        for(auto p : timings[player])
        {
            ll second_player = p[0];

            if(!infected[second_player] && (p[1] / (double)p[2]) >= start_time)
                {
                    check_infected(infected, timings, second_player, (p[1] / (double)p[2]));
                }
        }
    }
}

void solve(ll players, vector<vector<ll>> timings[], ll minimum_affected, ll maximum_affected)
{
    for(ll i=0; i<players; i++)
        {
            vector<int> infected(players, false);
            double start_time = 0.0;
            check_infected(infected, timings, i, start_time);

            ll curr_affected = count(infected.begin(), infected.end(), 1);

            minimum_affected = min(minimum_affected, curr_affected);
            maximum_affected = max(maximum_affected, curr_affected);
        }

        cout << minimum_affected << " " << maximum_affected << endl;
}

int main()
{
    ll t;

    cin >> t;

    while(t--)
    {
        ll players;
        cin >> players;

        vector<ll> velocity(players);

        for(ll i=0; i<players; i++)
            cin >> velocity[i];

        vector<vector<ll>> timings[players];

        create_timings(players, timings, velocity);

        ll minimum_affected = INT_MAX;
        ll maximum_affected = 1;

        solve(players, timings, minimum_affected, maximum_affected);
    }
}

