class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    
    int atMost(vector<int> &nums, int k)
    {
        int res = 0, start=0;
        
        for(int j=0; j<nums.size(); j++)
        {
            if(nums[j]%2 != 0)
            {
                k--;
            }
            while(k < 0)
            {
                k += nums[start] % 2;
                
                start++;
            }
            res += j - start + 1;
        }
        
        return res;
    }
};  