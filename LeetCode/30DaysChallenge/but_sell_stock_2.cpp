class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
            return 0;
        
        int profit = 0;
        
        int buy = prices[0];
        
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
            }
            else
            {
                while(i < prices.size() && prices[i] > prices[i-1])
                {
                    i++;
                }
                profit += prices[i - 1] - buy;
                i--;
                buy = INT_MAX;
            }
            
        }
        
        return profit;
    }
};