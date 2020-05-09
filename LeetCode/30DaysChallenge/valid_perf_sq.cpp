class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int l = 1, r = num;
        
        while(l <= r)
        {
            long mid = (l) + (r - l)/2;
            
            if(mid*mid == num)
                return 1;
            else if(mid*mid < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return 0;
    }
};