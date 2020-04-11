class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> cost_mid(n+1, INT_MAX);
        cost_mid[0] = cost_mid[1] = 0;
        
        for(int i=0; i<n; i++)
        {
            if(i+1 <= n)
                cost_mid[i+1] = min(cost_mid[i+1], cost_mid[i] + cost[i]);
            if(i+2 <= n)
                cost_mid[i+2] = min(cost_mid[i+2], cost_mid[i] + cost[i]);
        }
        
        return cost_mid[n];
    }
};