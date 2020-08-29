class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        int buses = routes.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i=0; i<buses; i++)
        {
            for(int j : routes[i])
                mp[j].push_back(i);
        }
        
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({s, 0});
        visited.insert(s);
        
        while(!q.empty())
        {
            auto top = q.front();
            int stop = top.first;
            int counts = top.second;
            q.pop();
            
            if(stop == t)
                return counts;
            
            for(int i : mp[stop])
            {
                for(int j : routes[i])
                {
                    if(visited.find(j) == visited.end())
                    {
                        visited.insert(j);
                        q.push({j, counts+1});
                    }
                }
                
                routes[i].clear();
            }
        }
        
        return -1;
    }
};