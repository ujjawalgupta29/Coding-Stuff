class Solution {
public:
    double angleClock(int hour, int min) {
        
        if(hour == 12)
            hour = 0;
        
        if(min == 60)
        {
            min = 0;
            hour += 1;
            if(hour > 12)
                hour = hour - 12;
        }
        
        double hour_hand = 0.5 * (hour*60 + min);
        double min_hand = 6 * min;
        
        double res = abs(hour_hand - min_hand);
        
        return (res < 360 - res) ? res : 360-res;
    }
};