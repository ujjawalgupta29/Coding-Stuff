static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum = INT_MIN;
        int n = nums.size();
        int curr_sum = 0;
        for(int i=0; i<k; i++)
        {
            curr_sum += nums[i];
        }
        
        max_sum = max(max_sum, curr_sum);
        int idx = 0;
        
        for(int i=k; i<n; i++)
        {
            curr_sum += nums[i] - nums[idx];
            idx++;
            max_sum = max(max_sum, curr_sum);
        }
        
        return (double)(max_sum)/k;
    }
};