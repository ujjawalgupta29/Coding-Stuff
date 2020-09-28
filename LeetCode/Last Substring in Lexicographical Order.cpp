class Solution {
public:
    string lastSubstring(string s) {
        int len = s.size();
        
        if(len < 2)
            return s;
        
        int first = 0;
        int second = 1; 
        int k = 0; //len_of_substr - 1
        
        while(second+k < len)
        {
            if(s[first+k] == s[second+k])
                k++;
            
            else if(s[first+k] > s[second+k])
            {
                second = second + k + 1;
                k=0;
            }
            
            else
            {
                first = second;
                second++;
                k=0;
            }
        }
        
        return s.substr(first);
    }
};