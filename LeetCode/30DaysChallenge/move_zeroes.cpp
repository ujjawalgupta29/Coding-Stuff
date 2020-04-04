class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int i=0;
        
        while(i < nums.size() && nums[i] != 0 )
        {
            i++;
            j++;
        }
        
        for(; i<nums.size(); i++)
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        
        for(auto x : nums) cout << x << " ";
        
        for(int k=j; k<nums.size();k++)
            nums[k] = 0;
    }
};