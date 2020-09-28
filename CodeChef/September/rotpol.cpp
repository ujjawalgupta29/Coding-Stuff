#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

ll maximum_coordinate = 2000000000;

void generate_at_diiferent_angles(vector<vector<ll>> &coordinates, ll x, ll y, ll for_x)
{
    if(for_x)
    {
        ll previous_value = 0;
        while(abs(x) <= maximum_coordinate)
        {
            coordinates.push_back(vector<ll>{x, y});

            if(abs(x) <= maximum_coordinate/2)
            {
                x *= 2;
                coordinates.push_back(vector<ll>{(previous_value+x)/2, y});
                previous_value = x;
            }
            else
            {
                break;
            }
            
        }
    }

    else
    {   
        ll previous_value = y;
        while(abs(y) <= maximum_coordinate)
        {
            coordinates.push_back(vector<ll>{x, y});

            if(abs(y) <= maximum_coordinate/2)
            {
                y *= 2;
                coordinates.push_back(vector<ll>{x, (y+previous_value)/2});
                previous_value = y;
            }
            else
            {
                break;
            }
            
        }
    }
    
}

bool isConditionSatisfied(vector<ll> &indexes)
{
    int n = indexes.size();

    if(n == 0)
        return true;
    
    ll first_idx = indexes[0];

    for(ll i=1; i<n; i++)
    {
        if(indexes[i] != first_idx + i)
            return false;
    }

    return true;
}

void take_input_points(vector<vector<ll>> &points_coordinates)
{
    int n = points_coordinates.size();
    for(int i=0; i<n; i++)
        cin >> points_coordinates[i][0] >> points_coordinates[i][1];
}

void generate_vectors(vector<vector<ll>> &vectors_present, vector<vector<ll>> &points_coordinates, ll n)
{
    for(int i=0; i<n-1; i++)
    {
        vectors_present[i][0] = points_coordinates[i+1][0] - points_coordinates[i][0];
        vectors_present[i][1] = points_coordinates[i+1][1] - points_coordinates[i][1];
    }

    vectors_present[n-1][0] = points_coordinates[0][0] - points_coordinates[n-1][0];
    vectors_present[n-1][1] = points_coordinates[0][1] - points_coordinates[n-1][1];
}

void generate_poosible_coordinates(vector<vector<ll>> &coordinates, vector<vector<ll>> &vectors_present)
{
    ll n = vectors_present.size();
    for(int i=0; i<n; i++)
    {
        coordinates.push_back(vectors_present[i]);
    }

    generate_at_diiferent_angles(coordinates, maximum_coordinate, 1, 0);
    generate_at_diiferent_angles(coordinates, 1, maximum_coordinate, 1);

    generate_at_diiferent_angles(coordinates, 1, -maximum_coordinate, 1);
    generate_at_diiferent_angles(coordinates, maximum_coordinate, -1, 0);

    generate_at_diiferent_angles(coordinates, -maximum_coordinate, -1, 0);
    generate_at_diiferent_angles(coordinates, -1, -maximum_coordinate, 1);

    generate_at_diiferent_angles(coordinates, -1, maximum_coordinate, 1);
    generate_at_diiferent_angles(coordinates, -maximum_coordinate, 1, 0);
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        vector<vector<ll>> points_coordinates(n, vector<ll>(2, 0));
        take_input_points(points_coordinates);

        vector<vector<ll>> vectors_present(n, vector<ll>(2, 0));

        generate_vectors(vectors_present, points_coordinates, n);

        vector<vector<ll>> coordinates = {
            {0, maximum_coordinate}, {maximum_coordinate, 0},
            {-maximum_coordinate, 0}, {0, -maximum_coordinate},

            {maximum_coordinate, -maximum_coordinate},{-maximum_coordinate, maximum_coordinate},
            {maximum_coordinate, maximum_coordinate}, {-maximum_coordinate, -maximum_coordinate}
        };

        generate_poosible_coordinates(coordinates, vectors_present);

        int result_xv=0, result_yv=0;

        for(ll i=0; i<coordinates.size(); i++)
        {
            vector<ll> positive_idx;
            vector<ll> negative_idx;

            bool exist = 1;

            for(ll j=0; j<n; j++)
            {
                ll temp = coordinates[i][0] * vectors_present[j][0] + coordinates[i][1] * vectors_present[j][1];

                if(temp > 0)
                {
                    positive_idx.push_back(j);
                }

                else if(temp == 0)
                {
                    exist = 0;
                    break;
                }

                else
                {
                    negative_idx.push_back(j);
                }
                
            }

            if( exist && ( isConditionSatisfied(positive_idx) || isConditionSatisfied(negative_idx) ) )
            {
                result_xv = coordinates[i][0];
                result_yv = coordinates[i][1];
                break;
            }
        }

        cout << result_xv << " " << result_yv << endl;
    }
}