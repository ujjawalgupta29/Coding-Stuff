class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        map<int, int> hash;
        hash[0] = -1;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i])
                count++;
            else
                count--;
            if(hash.find(count) != hash.end())
            {
                max_len = max(max_len, i - hash[count]);
            }
            else
                hash[count] = i;
        }
        
        return max_len;
    }
};