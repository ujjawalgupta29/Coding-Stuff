class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map < char, int > freq;
        
        for(char c : t)
            freq[c]++;
        
        int begin = 0, end = 0;
        int len = s.size();
        int min_len = INT_MAX;
        int counter = freq.size();
        string ans = "";
        
        while(end < len)
        {
            if(freq.find(s[end]) != freq.end())
            {
                freq[s[end]]--;
                if(freq[s[end]] == 0)
                    counter--;
            }
            end++;
            
            while(counter == 0)
            {
                if(end - begin  < min_len)
                {
                    min_len = end - begin;
                    ans = s.substr(begin, min_len);
                }
                
                if(freq.count(s[begin]) == 1)
                {
                    freq[s[begin]]++;
                    if(freq[s[begin]] > 0)
                        counter++;
                }
                
                begin++;
            }
        }
        
        return ans;
    }
};