class Solution {
public:
    
    bool check(vector<int> &nums, int mid, int k)
    {
        int n = nums.size();
        int counts = 0;
        int s=0, e=0;
        
        // while(e < n)
        // {
        //     if(nums[e] - nums[s] <= mid)
        //         e++;
        //     else
        //     {
        //         counts += e - s - 1;
        //         s++;
        //     }
        // }
        // counts += e - s - 1;
        
        while (s < n || e < n)
        {
            while (e < n && nums[e] - nums[s] <= mid)
            {
                e += 1;
            }
            counts += e - s - 1;
            s += 1;
        }
        
        return counts >= k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l=0, r=nums[n-1] - nums[0];
        
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            
            if(check(nums, mid, k))
                r = mid;
            else
                l = mid + 1;
        }
        
        return l;
    }
};