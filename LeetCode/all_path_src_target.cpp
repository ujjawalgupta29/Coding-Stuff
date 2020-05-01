class Solution {
public:
    
    void dfs(vector<int> &temp, vector<vector<int>>& graph, vector<vector<int>> &res, int node)
    {
        temp.push_back(node);
        if(node == graph.size() - 1)
            res.push_back(temp);
        else
        {
            for(int i : graph[node])
                dfs(temp, graph, res, i);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int src = 0;
        int dest = n - 1;
        vector<vector<int>> res;
        vector<int> temp;
        
        dfs(temp, graph, res, 0);
        
        return res;
    }
};