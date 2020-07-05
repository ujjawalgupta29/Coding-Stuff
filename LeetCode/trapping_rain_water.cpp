class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n == 0)
            return 0;
        
        vector<int> left(n);
        left[0] = height[0];
        
        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        
        int total_water = 0;
        int right_max = height[n-1];
        
        for(int i=n-2; i>=0; i--) {
            right_max = max(right_max, height[i]);
            total_water += min(left[i], right_max) - height[i];
        }
        
        return total_water;
    }
};

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();