class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n ,-1);
        
        map<int, int> mp;
        
        for(int i=0; i<n ;i++)
        {
            mp[intervals[i][0]] = i;
        }
            
        for(int i=0; i<n; i++)
        {
            auto it = mp.lower_bound(intervals[i][1]);
            if(it != mp.end())
                res[i] = mp[it->first];
        }
        
        return res;
    }
};