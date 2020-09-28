#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, powers, b) for(int i=powers; i<b; i++)
#define dfor(i, powers, b) for(int i=powers; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void initialize(vector<int> &powers)
{
    powers[0] = 1;

    for(int i=1; i<21; i++)
        powers[i] = 2*powers[i-1];
}

void grader_interact(int n, vector<int> &powers)
{
    cout << 1 << " " << powers[20] << endl;
    cout.flush();

    int sum;
    cin >> sum;

    sum = sum - powers[20]*n;

    int curr_xor = 0;

    if(sum % 2 == 1)
        curr_xor = curr_xor + 1;

    for(int i=1; i<20; i++)
    {
        int temp_sum = sum;
        temp_sum += (powers[i] * n);

        cout << 1 << " " << powers[i] << endl;
        cout.flush();

        int graderXor;
        cin >> graderXor;

        int res = ( (temp_sum - graderXor) / (powers[i] * 2) ) % 2;

        if(res != 0)
        {
            curr_xor += powers[i];
        }
    }

    cout << 2 << " " << curr_xor << endl;
    cout.flush();

    int grader_output;
    cin >> grader_output;
}

int main()
{
    int t;
    cin >> t;

    vector<int> powers(22, 0);

    initialize(powers);

    while(t--)
    {
        int n;
        cin >> n;

        grader_interact(n, powers);
    }
}