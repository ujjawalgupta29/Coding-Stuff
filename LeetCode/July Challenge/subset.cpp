class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_sets = pow(2, n);
        vector<vector<int>> res;
        
        for(int i=0; i<total_sets; i++)
        {
            vector<int> temp;
            int num = i;
            int counter = 0;
            
            while(num)
            {
                if(num & 1)
                {
                    temp.push_back(nums[counter]);
                }
                
                counter++;
                num = num >> 1;
            }
            res.push_back(temp);
        }
        
        return res;
    }
};