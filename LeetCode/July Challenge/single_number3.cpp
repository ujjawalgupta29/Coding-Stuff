class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        
        for(int x : nums)
            Xor = Xor ^ x;
        
        int lastSetBit = Xor & -Xor;
        
        int a=0, b=0;
        
        for(int x : nums)
        {
            if(lastSetBit & x)
                a = a^x;
            else
                b = b^x;
        }
        
        return vector<int> {a, b};
    }
};