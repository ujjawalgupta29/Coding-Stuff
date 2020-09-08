void dfs(int node, vector<vector<int>> &graph, vector<int> &p, vector<int> &q,
        vector<int> &A, vector<int> &B, vector<bool> &visited)
{
    p.push_back(A[node]);
    q.push_back(B[node]);
    visited[node] = 1;
    
    for(int v : graph[node])
    {
        if(!visited[v])
            dfs(v, graph, p, q, A, B, visited);
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    vector<vector<int>> graph(n);
    for(auto v : C)
    {
        v[0]--;
        v[1]--;
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    vector<bool> visited(n, 0);
    bool flag = 1;
    
    for(int i=0; i<n; i++)
    {
        vector<int> p;
        vector<int> q;
        if(!visited[i])
        {
            dfs(i, graph, p, q, A, B, visited);
        }
        
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        
        if(p != q)
        {
            flag = 0;
            break;
        }
    }
    
    return (flag) ? 1 : 0;
}
