class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ps = pow(2, nums.size());
        vector<vector<int>> sets;
        
        for(int i=0; i<ps; i++)
        {
            vector<int> temp = convert_i_set(i, nums);
            sets.push_back(temp);
        }
        return sets;
    }
    
    vector<int> convert_i_set(int val, vector<int> nums)
    {
        int index = 0;
        vector<int> set;
        
        while(val > 0)
        {
            if(val & 1)
            {
                set.push_back(nums[index]);
            }
            val = val >> 1;
            index++;
        }
        return set;
    }
};