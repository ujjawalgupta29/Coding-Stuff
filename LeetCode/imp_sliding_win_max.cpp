class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> indices;
        indices.push_back(0);
        
        for(int i=1; i<n; i++)
        {
            if(i >= k && indices[0] == (i-k))
            {
                res.push_back(nums[indices[0]]);
                indices.pop_front();
            }
            else if(i >= k)
                res.push_back(nums[indices[0]]);
            
            while(!indices.empty() && nums[i] > nums[indices.back()])
                indices.pop_back();
            indices.push_back(i);
        }
        res.push_back(nums[indices[0]]);
        
        return res;
    }
};