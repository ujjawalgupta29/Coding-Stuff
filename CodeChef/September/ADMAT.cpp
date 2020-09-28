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

void initialize(vector<vector<ll>> &result_matrix, ll number, ll rows)
{
    for(int i=0; i<rows; i++)
        {
            for(int j=0; j<rows; j++)
            {
                result_matrix[i][j] = number;
                number++;
            }
        }
}

void transpose_ith_row(vector<vector<int>> &matrix, int rows)
{
    //change only needed row
    for(int i=0; i<rows; i++)
    {
        swap(matrix[0][i], matrix[i][0]);
    }
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll rows;
        cin >> rows;

        ll matrix[rows][rows];

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<rows; j++)
            {
                cin >> matrix[i][j];
            }
        }

        vector<vector<ll>> result_matrix(rows, vector<ll>(rows));
        //matrix to be
        initialize(result_matrix, 1, rows);

        int swaps_needed = 0;

        for(int i=rows-1; i>=1; i--)
        {
            if(matrix[0][i] != result_matrix[0][i])
            {
                swaps_needed++;
                transpose_ith_row(matrix, i);
            }
        }

        cout << swaps_needed << endl;
        
    }
}