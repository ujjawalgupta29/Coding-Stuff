class Solution {
public:
    
    int dfs(vector<vector<int>> &graph, int cost, int node, 
            vector<bool>& hasApple, unordered_map<int, bool> visited)
    {
        if(visited[node])
            return 0;
        
        visited[node] = 1;
        
        int child_cost = 0;
        for(int x : graph[node])
        {
            child_cost += dfs(graph, 2, x, hasApple, visited);
        }
        
        if(child_cost == 0 && hasApple[node] == 0)
            return 0;
        
        return cost+child_cost;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        unordered_map<int, bool> visited;
        for(auto v : edges)
        {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        return dfs(graph, 0, 0, hasApple, visited);
    }
};