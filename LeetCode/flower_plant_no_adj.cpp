class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);
        vector<int> res(N);
        
        for(auto p : paths)
        {
            graph[p[0]-1].push_back(p[1]-1);
            graph[p[1]-1].push_back(p[0]-1);
        }
        
        for(int i=0; i<N; i++)
        {
            vector<int> color(5, 0);
            for(int j : graph[i])
            {
                color[res[j]] = 1;
            }
            
            for(int j = 1; j<=4; j++)
            {
                if(!color[j])
                {
                    res[i] = j;
                }
            }
        }
        
        return res;
    }
};