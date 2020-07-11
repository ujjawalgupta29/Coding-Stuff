static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();        
        stack<int> st;
        vector<int> res(prices.begin(), prices.end());
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && prices[st.top()] >= prices[i])
            {
                res[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};