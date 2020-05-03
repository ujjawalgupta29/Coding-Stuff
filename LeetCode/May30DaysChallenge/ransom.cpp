class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for(char c : magazine)
            mag[c]++;
        
        for(char c : ransomNote)
        {
            if(mag.find(c) != mag.end())
            {
                mag[c]--;
                if(mag[c] < 0)
                    return 0;
            }
            else
                return 0;
        }
        
        return 1;
    }
};