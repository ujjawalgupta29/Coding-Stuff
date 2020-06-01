class Solution {
public:
    
    string build(string s1, string s2)
    {
        int idx1=0, idx2=0;
        string res;
        
        while(idx2 < s2.size())
        {
            res += s1[idx1++];
            res += s2[idx2++];
        }
        
        if(idx1 < s1.size())
            res += s1[idx1];
        
        return res;
    }
    
    string reformat(string s) {
        string num = "";
        string alpha = "";
        
        int len = s.size();
        
        for(int i=0; i<len; i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                alpha += s[i];
            else
                num += s[i];
        }
        
        int alpha_len = alpha.size();
        int num_len = num.size();
        
        if(abs(alpha_len - num_len) > 1)
            return "";
        
        if(alpha_len > num_len)
        {
            return build(alpha, num);
        }
        
        return build(num, alpha);
    }
};