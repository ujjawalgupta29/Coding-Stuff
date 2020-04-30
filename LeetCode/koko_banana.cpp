class Solution {
public:
    
    bool check(int speed, vector<int> piles, int H)
    {
        int time = 0;
        for(int x : piles)
            time += ceil((float)x/speed);
        return time <= H;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        
        int max_speed = 0;
        
        for(int x : piles)
            max_speed = max(max_speed, x);
        
        int min_speed = max_speed;
        
        int l = 1;
        int r = max_speed;
        
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(mid, piles, H))
            {
                min_speed = min(min_speed, mid);
                r = mid - 1;
            }
            
            else
                l = mid + 1;
        }
        
        return min_speed;
    }
};