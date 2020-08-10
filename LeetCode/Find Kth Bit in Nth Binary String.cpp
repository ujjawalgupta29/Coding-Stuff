class Solution {
public:
    char findKthBit(int n, int k) {
        bool flip = 0;
        k--;
        
        while(n > 1)
        {
            int curr_len = pow(2, n) - 1;
            int mid = curr_len / 2;
  
            
            if(k == mid)
                return (flip) ? '0' : '1';
            
            else if(k > mid)
            {
                n--;
                flip = !flip;
                k = (pow(2, n) - 1) - (k - mid);
            }
            
            else
            {
                n--;
                // flip = 0;
            }
            
        }
        
        return (flip) ? '1' : '0';
    }
};