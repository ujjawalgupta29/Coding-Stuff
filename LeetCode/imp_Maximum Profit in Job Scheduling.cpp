class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>> times;
        int n = p.size();
        
        for(int i=0; i<n; i++)
            times.push_back(vector<int>{e[i], s[i], p[i]});
        
        sort(times.begin(), times.end());
        
        map<int, int> dp;
        dp[0] = 0;
        
        for(auto job : times)
        {
            int temp_profit = prev(dp.upper_bound(job[1]))->second + job[2];
            if(temp_profit > dp.rbegin()->second)
                dp[job[0]] = temp_profit;
        }
        
        return dp.rbegin()->second;
    }
};