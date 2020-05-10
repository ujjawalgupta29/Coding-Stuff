class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> seen;
        seen.insert(0);
        
        stack<int> dfs;
        dfs.push(0);
        
        while(!dfs.empty())
        {
            int node = dfs.top();
            dfs.pop();
            
            for(int v : rooms[node])
            {
                if(seen.count(v) == 0)
                {
                    dfs.push(v);
                    seen.insert(v);
                    if(seen.size() == rooms.size())
                        return 1;
                }
            }
        }
        
        return seen.size() == rooms.size();
    }
};