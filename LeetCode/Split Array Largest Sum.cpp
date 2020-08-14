class Solution {
public:
    
    //th->threshold
    bool check(vector<int> &nums, int th, int m)
    {
        int counts = 1;
        int sum = 0;
        
        for(int x : nums)
        {
            sum += x;
            if(sum > th)
            {
                sum = x;
                counts++;
                if(counts > m)
                    return 0;
            }
        }
        
        return 1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l=0,r;
        long sum=0;
        for(int x : nums)
        {
            sum += x;
            l = max(l, x);
        }
        r = sum;
        
        while(l < r)
        {
            int mid = l + (r-l) / 2;
            
            if(check(nums, mid, m))
            {
                r = mid;
            }
            
            else
                l = mid + 1;
        }
        
        return l;
    }
};