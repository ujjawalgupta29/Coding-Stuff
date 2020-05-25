class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        
        vector<int> sold(n, 0);
        vector<int> buy(n, 0);
        vector<int> rest(n, 0);
        
        buy[0] = -prices[0];
        rest[0] = INT_MIN;
        
        for(int i=1; i<n; i++)
        {
            sold[i] = max(rest[i-1], sold[i-1]);
            buy[i] = max(sold[i-1] - prices[i], buy[i-1]);
            rest[i] = prices[i] + buy[i-1];
        }
        
        return max(sold[n-1], rest[n-1]);
    }
};