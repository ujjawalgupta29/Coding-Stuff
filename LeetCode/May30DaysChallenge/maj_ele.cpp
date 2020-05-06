class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int occ = n/2 + 1;
        
        map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            if(++mp[nums[i]] == occ)
                return nums[i];
        }
        // cout<<" = "<<mp[3]<<endl;
        
        return -1;
    }
};