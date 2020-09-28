    #include<bits/stdc++.h>
    using namespace std;

    void dfs(vector<bool> &visited, vector<vector<int>>player[], int p, double time)
    {
        if(!visited[p])
        {
            visited[p] = 1;
            for(auto v : player[p])
            {
                int x = v[0];

                if(!visited[x] && double((double)v[1] / (double)v[2]) >= time)
                {
                    dfs(visited, player, x, double((double)v[1] / (double)v[2]));
                }
            }
        }
    }

    int countOne(vector<bool> &visited)
    {
        int counts = 0;
        for(int i=0; i<visited.size(); i++)
        {
            if(visited[i])
                counts++;
        }

        return counts;
    }

    int main()
    {
        int t;
        cin >> t;

        while(t--)
        {
            int n;
            cin >> n;

            vector<int> v(n);

            for(int i=0; i<n; i++)
                cin >> v[i];

            vector<vector<int>> player[n];

            for(int i=0; i<n; i++)
            {
                //backward
                for(int j=0; j<i; j++)
                {
                    if(v[j] > v[i])
                    {
                        int num  = i - j;
                        int denom = v[j] - v[i];
                        player[i].push_back({j, num, denom});
                    }
                }
                //forward
                for(int j=i+1; j<n; j++)
                {
                    if(v[j] < v[i])
                    {
                        int num  = j - i;
                        int denom = v[i] - v[j];
                        player[i].push_back({j, num, denom});
                    }
                }

                // player[i].push_back(i);
            }

            int mini = INT_MAX;
            int maxi = 1;

            if(n == 3)
            {
                for(int i=0; i<n; i++)
                {
                    int sz = player[i].size() + 1;
                    mini = min(mini, sz);
                    maxi = max(maxi, sz);
                }
            }

            else
                for(int i=0; i<n; i++)
                {
                    vector<bool> visited(n, 0);

                    dfs(visited, player, i, 0.0);

                    int affected = countOne(visited);

                    mini = min(mini, affected);
                    maxi = max(maxi, affected);
                }

            cout << mini << " " << maxi << endl;
        }
    }