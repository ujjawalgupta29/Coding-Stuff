class Solution {
public:
    string pushDominoes(string s) {
        s = 'L' + s + 'R';
        int len = s.size();
        string res="";
        
        int i=0;
        for(int j=1; j<len; j++)
        {
            if(s[j] == '.')
                continue;
            
            int middle_char = j - i - 1;
            
            if(i > 0)
                res += s[i];
            
            if(s[i] == s[j])
            {
                res += string(middle_char, s[i]);
            }
            
            else if(s[i] == 'L' && s[j] == 'R')
            {
                res += string(middle_char, '.');
            }
            
            else
            {
                res += string(middle_char/2, 'R') + string(middle_char%2, '.') 
                    + string(middle_char/2, 'L');
            }
            i = j;
        }
        
        return res;
    }
};