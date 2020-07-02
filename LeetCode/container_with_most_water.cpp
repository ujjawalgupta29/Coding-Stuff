class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        long long l = 0, r = n-1;
        
        long long max_water = INT_MIN;
        
        while(l < r) {
            max_water = max(max_water, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        
        return max_water;
    }
};