class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> bits(32, 0);
        
        for(int i=0; i<32; i++) {
            for(int n : nums) {
                bits[i] += (n >> i) & 1;
                bits[i] %= 3;
            }
        }
        
        for(int i=0; i<32; i++) {
            res |= (bits[i] << i);
        }
        
        return res;
    }
};