class Solution {
public:
    int maxPower(string s) {
        int max_len = 1;
        
        char ch = s[0];
        int temp_len= 1;
        
        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == ch)
                temp_len++;
            else
            {
                max_len = max(max_len, temp_len);
                temp_len = 1;
            }
            
            ch = s[i];
        }
        max_len = max(max_len, temp_len);
        
        return max_len;
    }
};