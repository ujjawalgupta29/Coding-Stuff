class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        int src = 0;
        for(int dest = 0; src <= dest && src < n; src++)
        {
            dest = max(dest, src + nums[src]);
        }
        
        return src==n;
    }

};