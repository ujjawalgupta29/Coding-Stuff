class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int n = dislikes.size();
        vector<vector<int>> graph(N);
        
        for(auto v: dislikes)
        {
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        
        vector<int> visited(N, 0);
        queue<int> q;
        
        for(int i=0; i<N; i++)
        {
            if(visited[i])
                continue;
            
            q.push(i);
            visited[i] = 1;
            
            while(!q.empty())
            {
                int u = q.front(), v;
                q.pop();
                
                for(int j=0; j<graph[u].size(); j++)
                {
                    v = graph[u][j];
                    if(visited[v] == 0)
                    {
                        q.push(v);
                        visited[v] = (visited[u] == 1) ? 2 : 1;
                    }
                    
                    if(visited[v] == visited[u])
                        return 0;
                }
            }
        }
        
        return 1;
    }
};