class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2)
            return false;
        
        
        int a = INT_MAX;
        int b = INT_MAX;
        for(int x : nums)
        {
            if(x <= a)
                a = x;
            else if(x <= b)
                b = x;
            else
                return true;
        }
        
        return false;
    }
};