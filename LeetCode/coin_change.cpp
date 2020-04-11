static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int denom=0; denom<n; denom++)
        {
            for(int amt = 1; amt<=amount; amt++)
            {
                if(coins[denom] <= amt)
                {
                    dp[amt] = min(dp[amt], 1 + dp[amt - coins[denom]]);
                }
            }
        }
        
        return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};