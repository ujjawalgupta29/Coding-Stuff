#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(int x, int y, vector<vector<int>> adj)
{
    vector<int> path;
    path.push_back(x);

    queue<vector<int>> q;
    q.push(vector<int>{x});

    vector<bool> visited(n, 0);
    
    int len = INT_MAX;

    while(!q.empty())
    {
        int sz = q.size();

        for(int s=0; s<sz; s++)
        {
            vector<int> top = q.front();
            q.pop();

            int last_node = top.back(); //last node

            if(last_node == y)
                return top;

            visited[last_node] = 1;

            for(int i=0; i<adj[last_node].size(); i++)
            {
                if(!visited[adj[last_node][i]])
                {
                    vector<int> temp;
                    temp.push_back(adj[last_node][i]);
                    q.push(temp);
                }
            }
        }
       len++;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> friends(n, vector<int>(2));

    for(int i=0; i<n; i++)
        cin >> friends[i][0] >> friends[1];

    
}