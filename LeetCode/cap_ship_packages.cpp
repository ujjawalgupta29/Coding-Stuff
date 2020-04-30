class Solution {
public:
    
    bool check(int cap, vector<int> weights, int D)
    {
        int time = 1;
        int sum = 0;
        
        for(int x : weights)
        {
            sum += x;
            if(sum > cap)
            {
                time++;
                sum = x;
            }
        }
        
        return time <= D;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int min_cap = 0;
        int max_ele = INT_MIN;
        
        for(int x : weights)
        {
            min_cap += x;
            max_ele = max(max_ele, x);
        }
        
        int l = max_ele;
        int r = min_cap;
        int ans = min_cap;
        
        while(l <= r)
        {
            int mid = (l + r) / 2;
            
            if(check(mid, weights, D))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            
            else
                l = mid + 1;
        }
        
        return ans;
    }
};