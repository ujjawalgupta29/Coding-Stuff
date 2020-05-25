class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.length() < s1.length())
            return false;
        
        unordered_map<char, int> freq;
        for(char c : s1)
            freq[c]++;
        
        int counter = freq.size();
        int begin = 0;
        int len = s1.length();
        
        for(int i=0; i<s2.size(); i++)
        {
            if(freq.count(s2[i]) == 1)
            {
                freq[s2[i]]--;
                if(freq[s2[i]] == 0)
                    counter--;
            }
            
            while(counter == 0)
            {
                if(i - begin + 1 == len)
                    return true;
                
                if(freq.count(s2[begin]) == 1)
                {
                    freq[s2[begin]]++;
                    if(freq[s2[begin]] > 0)
                        counter++;
                }
                
                begin++;
            }
        }
        
        return false;
    }
};