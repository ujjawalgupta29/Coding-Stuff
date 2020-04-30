class Solution {
public:
    
    int find_msb(int num)
    {
        int pos = -1;
        
        while(num)
        {
            num = num >> 1;
            pos++;
        }
        
        return pos;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        
        int res = 0;
        
        while(n > 0 && m > 0)
        {
            int msb_m = find_msb(m);
            int msb_n = find_msb(n);
            // cout << msb_m << " " << msb_n << endl;
            
            if(msb_m != msb_n)
                break;
            
            int val = pow(2, msb_m);
            res += val;
            
            m = m - val;
            n = n - val;
        }
        
        return res;
    }
};