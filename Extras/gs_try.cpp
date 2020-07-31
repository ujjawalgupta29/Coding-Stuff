#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



// Complete the closestStraightCity function below.
vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) {

    int n = c.size();
    unordered_map<string, pair<int, int>> mp;
    for(int i=0; i<n; i++)
    {
        mp[c[i]] = {x[i], y[i]};
    }

    vector<string> ans;

    for(int i=0; i<q.size(); i++)
    {
        int x1 = mp[q[i]].first;
        int y1 = mp[q[i]].second;
        long long int min_dist = LONG_MAX;
        string res = "NONE";

        for(long j=0; j<n; j++)
        {
            if(c[j] != q[i] && (x[j] == x1 || y[j] == y1))
            {
                long long int dist;
                if(x[j] == x1)
                {
                    dist = (y[j] - y1)*(y[j] - y1);
                }
                
                else if(y[j] == y1)
                {
                    dist = (x[j] - x1) * (x[j] - x1);
                }
                
                if(dist < min_dist)
                {
                    min_dist = dist;
                    res = c[j];
                }
                else if(dist == min_dist && res > c[j])
                {
                    res = c[j];
                }
            }
        }
        ans.push_back(res);
    }
    return ans;
}

int main()