#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int ways(string exp, int res, unordered_map< string, int> &memo)
{

    if(exp.length() == 0)
        return 0;
    if(exp.length() == 1)
    {
        if(stoi(exp) == res)
            return 1;
        else
        {
            return 0;
        }
    }

    if(memo.find(to_string(res) + exp) != memo.end())
        return memo[to_string(res) + exp];

    int total_ways = 0;

    for(int i = 1; i<exp.size(); i+= 2)
    {
        string left = exp.substr(0, i);
        string right = exp.substr(i+1);

        int leftFalse = ways(left, 0, memo);
        int leftTrue = ways(left, 1, memo);
        int rightFalse = ways(right, 0, memo);
        int rightTrue = ways(right, 1, memo);
        int total = (leftFalse + leftTrue) * (rightTrue + rightFalse);

        int total_true = 0;
        if(exp[i] == '|')
        {
            total_true = (leftTrue * rightFalse) + (leftTrue * rightTrue) + (leftFalse * rightTrue);
        }

        else if(exp[i] == '^')
        {
            total_true = (leftTrue * rightFalse) + (leftFalse * rightTrue);
        }

        else if(exp[i] == '&')
        {
            total_true = (leftTrue * rightTrue);
        }

        total_ways += (res) ? total_true : (total - total_true);
    }
    memo[to_string(res) + exp] = total_ways;
    return total_ways;
}

int main()
{
    //Code
    string exp;
    cin >> exp;
    int result;
    cin >> result;
    unordered_map<string, int> memo;

    cout << ways(exp, result, memo) <<endl;

    return 0;
}