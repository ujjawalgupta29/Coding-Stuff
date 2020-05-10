class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1)
            return 1;
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<trust.size(); i++)
        {
            mp[trust[i][1]]++;
            mp[trust[i][0]]--;
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == N-1)
                return it->first;
        }
        
        return -1;
    }
};