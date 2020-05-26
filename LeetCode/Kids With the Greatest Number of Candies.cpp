static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size();
        
        int max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> res(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(candies[i] + extra >= max_candies)
                res[i] = 1;
        }
        
        return res;
    }
};