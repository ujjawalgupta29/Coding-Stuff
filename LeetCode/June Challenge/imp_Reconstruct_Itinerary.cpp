class Solution {
public:
    
    int n=0;
    
    void dfs(unordered_map<string, multiset<string>> &mp,
             string from, vector<string> &res) {
        while(mp[from].size()) {
            string next = *mp[from].begin();
            mp[from].erase(mp[from].begin());
            dfs(mp, next, res);
        }
        res.push_back(from);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        n = tickets.size();
        
        unordered_map<string, multiset<string>> mp;
        
        for(int i=0; i<n; i++) {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        dfs(mp, "JFK", res);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};