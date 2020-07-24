class Solution {
public:
    
    int getVal(string s, int idx)
    {
        if(idx >= s.size())
            return 0;
        
        return s[idx] - '0';
    }
    
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        
        int carry = 0;
        int len1 = a.size();
        int len2 = b.size();
        
        int i=0, j=0;
        
        while(i < len1 || j < len2 || carry)
        {
            int x = getVal(a, i);
            int y = getVal(b, j);
            
            int sum = x + y + carry;
            int value = sum % 2;
            carry = sum / 2;
            
            res.append(to_string(value));
            
            i++;
            j++;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};