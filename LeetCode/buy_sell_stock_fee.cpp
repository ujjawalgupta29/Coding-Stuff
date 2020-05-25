class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0, buy = INT_MIN;
        int temp;
        
        for(int p : prices)
        {
            temp = sell;
            buy = max(buy, sell - p);
            sell = max(sell, buy + p - fee);
        }
        
        return sell;
    }
};