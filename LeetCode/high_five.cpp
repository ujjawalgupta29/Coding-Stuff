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

vector<vector<int>> high_five(vector<vector<int>> &scores)
{
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    for(auto it : scores)
    {
        mp[it[0]].push(it[1]);
        if(mp[it[0]].size() > 5)
        {
            mp[it[0]].pop();
        }
    }

    vector<vector<int>> res;

    for(auto it : mp)
    {
        int score = 0;
        while(mp[it.first].size())
        {
            score += mp[it.first].top();
            mp[it.first].pop();
        }

        res.push_back(vector<int>{it.first, score/5});
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> scores;
    int id, sc;
    for(int i=0; i<n; i++)
    {
        cin >> id >> sc;
        scores.push_back(vector<int>{id, sc});
    }

    vector<vector<int>> res = high_five(scores);

    for(auto it : res)
    {
        for(int x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
// Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
// Output: [[1,87],[2,88]]