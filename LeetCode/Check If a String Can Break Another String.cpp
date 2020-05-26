class Solution {
public:
    
    string build(string s)
    {
        vector<int> counts(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            counts[s[i] - 'a']++;
        }
        
        string res;
        for(int i=0; i<26; i++)
        {
            res += string(counts[i], 'a'+i);
        }
        
        return res;
    }
    
    bool check(string first, string second)
    {
        int n = first.size();
        
        for(int i=0; i<n; i++)
        {
            if(first[i] > second[i])
                return 0;
        }
        
        return 1;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        string new_s1 = build(s1);
        string new_s2 = build(s2);
        
        if(check(new_s1, new_s2))
            return 1;
        
        if(check(new_s2, new_s1))
            return 1;
        
        return 0;
    }
};