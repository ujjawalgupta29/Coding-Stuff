class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& rooms, vector<int> &visited)
    {
        if(visited[node])
            return;
        
        visited[node] = 1;
        for(int i=0; i<rooms[node].size(); i++)
        {
            int v = rooms[node][i];
            if(!visited[v])
                dfs(v, rooms, visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<int> visited(N,0);
        // visited[0] = 1;
        for(int i=0; i<N; i++)
        {
            int node = 0;
            if(!visited[node])
            {
                dfs(node, rooms, visited);
            }
        }
        
        int counts = 0;
        for(int i=0; i<N; i++)
        {
            if(visited[i])
                counts++;
        }
        
        return counts==N;
    }
};