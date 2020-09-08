void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    if(visited[node])
        return;
        
    visited[node] = 1;
    
    for(int v : adj[node])
    {
        if(!visited[v])
        {
            dfs(v, adj, visited);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A+1, 0);
    vector<vector<int>> adj(A+1);
    
    for(auto v : B)
    {
        adj[v[0]].push_back(v[1]);
    }
    
    dfs(1, adj, visited);
    
    if(visited[A])
        return 1;
        
    return 0;
}
