class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums;
        nums.push_back(1);
        
        int x=0, y=0, z=0;
        
        while(nums.size() != n)
        {
            nums.push_back(min(nums[x]*2, min(nums[y]*3, nums[z]*5)));
            if(nums.back() == nums[x]*2)
                x++;
            
            if(nums.back() == nums[y]*3)
                y++;
            
            if(nums.back() == nums[z]*5)
                z++;
        }
        
        return nums[nums.size()-1];
    }
};