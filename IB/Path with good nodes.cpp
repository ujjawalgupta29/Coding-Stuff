int counts = 0;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, int c,
        vector<int> &A, int curr)
{
    if(visited[node])
        return;
        
    visited[node] = 1;
    curr += (A[node-1] == 1) ? 1 : 0;
    
    bool flag = 0;
    
    for(int v : adj[node])
    {
        if(!visited[v])
        {
            flag = 1;
            dfs(v, visited, adj, c, A, curr);
        }
    }
    
    if(flag == 0 && curr <= c)
    {
        counts++;
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    counts = 0;
    vector<vector<int>> adj(n+1);
    
    for(auto v : B)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    vector<bool> visited(n+1, 0);
    
    dfs(1, visited, adj, C, A, 0);
    
    return counts;
}
