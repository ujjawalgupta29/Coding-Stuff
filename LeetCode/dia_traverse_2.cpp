class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        unordered_map<int, vector<int> > mp;
        int dia = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                mp[i+j].push_back(nums[i][j]);
                dia = max(dia, i+j);
            }
        }
        
        for(int i=0; i<=dia; i++)
        {
            auto it = mp.find(i);
            if(it != mp.end())
            {
                int sz = it->second.size();
                for(int j=sz-1; j>=0; j--)
                    res.push_back(it->second[j]);
            }
        }
        
        return res;
    }
};