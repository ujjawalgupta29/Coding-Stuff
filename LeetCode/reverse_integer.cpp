class Solution {
public:
    int reverse(int x) {
        long num = 0;
        
        while(x)
        {
            num = num*10 + (x%10);
            x = x/10;
        }
        
        if(num < INT_MIN || num > INT_MAX)
            return 0;
        
        return num;
    }
};