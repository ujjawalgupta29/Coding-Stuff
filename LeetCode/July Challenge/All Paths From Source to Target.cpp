class Solution {
public:
    
    vector<vector<int>> res;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        int n = graph.size();
        dfs(graph, 0, n-1, temp);
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, int node, int target, vector<int> &temp)
    {
        temp.push_back(node);
        
        if(node == target)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0; i<graph[node].size(); i++)
        {
            dfs(graph, graph[node][i], target, temp);
            temp.pop_back();
        }
    }
};