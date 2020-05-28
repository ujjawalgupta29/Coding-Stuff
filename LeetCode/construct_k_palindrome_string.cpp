class Solution {
public:
    bool canConstruct(string s, int k) {
        int len = s.size();
        
        if(len < k)
            return 0;
        
        if(len == k)
            return 1;
        
        vector<int> mp(26, 0);
        
        for(char c : s)
        {
            mp[c- 'a']++;
        }
        
        int odd=0, even=0;
        
        for(int i = 0; i < 26; i++)
        {
            if(mp[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        
        if(odd <= k)
            return 1;
        
        return 0;
    }
};