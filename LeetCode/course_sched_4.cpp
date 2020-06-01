class Solution {
public:
    
    bool check(vector<vector<int>> &pre, int target, int course, bool res, vector<bool> &visited)
    {
        if(res)
            return res;
        
        if(target == course)
        {
            res = 1;
            return res;
        }
            
        visited[course] = 1;
        
        for(auto v : pre[course])
        {
            if(!visited[v])
            {
                res |= check(pre, target, v, res, visited);
            }
        }
        
        return res;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& q) {
        vector<vector<int>> pre(n);
        
        for(auto v : prerequisites)
        {
            pre[v[1]].push_back(v[0]);
        }
        
        vector<bool> res;
        
        for(auto v : q)
        {
            vector<bool> visited(n, 0);
            res.push_back(check(pre, v[0], v[1], 0, visited));
        }
        
        return res;
    }
};