class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        unordered_map<char, int> mp;
        bool flag = 0;
        
        for(char ch : s)
            mp[ch]++;
        
        int len_even = 0;
        
        for(auto it : mp)
        {
            if(it.second % 2 == 0)
                len_even += it.second;
            
            else
            {
                len_even += it.second - 1;
                flag = 1;
            }
        }
        
        if(flag)
            len_even++;
        
        return len_even;
    }
};