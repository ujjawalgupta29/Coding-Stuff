class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double res1 = 1;
        double res2 = 0.5;
        if(n==1)
            return res1;
        else
            return res2;
    }
};