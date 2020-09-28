pair<int, int> findMaxNode(int node, int n, vector<vector<int>> &adj)
{
    vector<bool> visited(n, 0);
    queue<pair<int, int>> q;
    q.push({node, 0});
    visited[node] = 1;
    int max_dist = 0;
    int max_node = node;
    
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        
        int curr_node = top.first;
        int curr_dist = top.second;
        if(max_dist < curr_dist)
        {
            max_dist = curr_dist;
            max_node = curr_node;
        }
        
        for(int i=0; i<adj[curr_node].size(); i++)
        {
            if(!visited[adj[curr_node][i]])
            {
                q.push({adj[curr_node][i], curr_dist+1});
                visited[adj[curr_node][i]] = 1;
            }
        }
        
    }
    
    return {max_node, max_dist};
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> adj(n);
    int root;
    
    for(int i=0; i<n; i++)
    {
        if(A[i] == -1)
            root = i;
            
        else
        {
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
    }
    
    pair<int, int> res1 = findMaxNode(root, n, adj);
    pair<int, int> res = findMaxNode(res1.first, n, adj);
    
    return res.second;
}