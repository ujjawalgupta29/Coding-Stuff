class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        
        for(auto v : paths)
        {
            mp[v[0]]++;
            if(mp.find(v[1]) == mp.end())
            {
                mp[v[1]] = 0;
            }
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == 0)
                return it->first;
        }
        
        return "";
    }
};