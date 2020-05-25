class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        int len_s = s.size();
        int len_p = p.size();
        int counts= 0;
        vector<int> ana;
        if(len_p > len_s)
            return ana;
        
        for(int i=0; i<len_p; i++)
        {
            if(mp.find(p[i]) != mp.end())
            {
                mp[p[i]]++;
            }
            else
            {
                mp[p[i]]++;
                counts++;
            }
        }
        // cout << counts << endl;
        
        //sliding window
        int idx = 0;
        for(int i=0; i<len_s; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] > 0)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    {
                        counts--;
                    }
                    if(counts == 0 && i - idx + 1 == len_p)
                        ana.push_back(idx);
                }
                
                else
                {
                    while(mp[s[i]] <= 0)
                    {
                        if(mp.find(s[idx]) != mp.end())
                        {
                            if(mp[s[idx]] == 0)
                                counts++;
                            mp[s[idx]]++;
                        }
                        idx++;
                    }
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    {
                        counts--;
                    }
                    if(counts == 0 && i - idx + 1 == len_p)
                        ana.push_back(idx);
                }
            }
            
            else
            {
                while(idx != i)
                {
                    if(mp.find(s[idx]) != mp.end())
                    {
                        if(mp[s[idx]] == 0)
                            counts++;
                        mp[s[idx]]++;
                    }
                    idx++;
                }
                idx++;
            }
        }
        
        return ana;
        
    }
};