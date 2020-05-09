class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        
        if(len_s > len_t)
            return 0;
        
        int j = 0;
        for(int i=0; i<len_t; i++)
        {
            if(t[i] == s[j])
                j++;
            if(j == len_s)
                return 1;
        }
        
        return (j == len_s);
    }
};