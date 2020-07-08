class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        
        int carry = 0;
        int val = digits[len-1] + 1;
        digits[len-1] = val % 10;
        carry = val/10;
        
        int idx = len-2;
        while(idx >= 0 && carry)
        {
            int temp = digits[idx] + carry;
            digits[idx] = temp % 10;
            carry = temp / 10;
            idx--;
        }
        
        if(carry)
        {
            reverse(digits.begin(), digits.end());
            digits.push_back(carry);
            reverse(digits.begin(), digits.end());
        }
        
        return digits;
    }
};