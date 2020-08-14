class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return 0;
        
        int power2 = log2(num);
        
        if(power2 % 2 != 0)
            return 0;
        
        if(pow(2, power2) == num)
            return 1;
        
        return 0;
    }
};