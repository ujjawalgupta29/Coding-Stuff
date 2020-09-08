long long ans;
long long mod = 1e9 + 7;

long long dfs(int node, vector<vector<int>> &adj, vector<bool> &visited,
            vector<long long> &sum_subtree, vector<int> &wt)
{
    if(visited[node])
        return 0;
        
    // cout << "Node:- " << node << endl;
        
    visited[node] = 1;
    long long sum = wt[node-1];
    
    for(int v : adj[node])
    {
        sum += dfs(v, adj, visited, sum_subtree, wt);
        sum % mod;
    }
    
    // cout << "sum = " << sum << endl;
    
    return sum_subtree[node] = sum;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    ans = INT_MIN;
    int n = A.size();
    vector<long long> sum_subtree(n+1, 0);
    
    vector<vector<int>> adj(n+1);
    
    for(auto v : B)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    vector<bool> visited(n+1, 0);
    
    long long sum = dfs(1, adj, visited, sum_subtree, A);
    
    // cout << sum << endl;
    
    // for(int x : sum_subtree)
    //     cout << x << " ";
        
    // cout << endl;
    
    for(auto v : B)
    {
        long long sum_x = sum_subtree[v[0]];
        long long sum_y = sum_subtree[v[1]];
        
        long long first = min(sum_x, sum_y);
        long long second = sum - first;
        
        // cout << first << " " << second << endl;
        
        ans = max(ans, (first*second)%mod);
    }
    
    return ans % mod;
}
