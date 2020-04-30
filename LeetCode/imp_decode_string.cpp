class Solution {
public:
    string build(string s, int& idx)
    {
        string res;
        
        while(idx < s.length() && s[idx] != ']')
        {
            if(!isdigit(s[idx]))
            {
                res += s[idx];
                idx++;
            }
            
            else
            {
                int n = 0;
                while(idx < s.length() && isdigit(s[idx]))
                {
                    n = n*10 + (s[idx] - '0');
                    idx++;
                }
                
                idx++; //'['
                string temp = build(s, idx);
                idx++; //']'
                
                while(n--)
                {
                    res += temp;
                }
            }
        }
        
        return res;
    }
    string decodeString(string s) {
        int i=0;
        return build(s, i);
    }
};