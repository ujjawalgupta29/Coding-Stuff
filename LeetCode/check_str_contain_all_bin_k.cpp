class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(k > 15)
            return 0;
        
        int len = s.size();
        unordered_set<string> set;
        
        for(int i=0; i<=len-k; i++)
        {
            set.insert(s.substr(i, k));
        }
        
        return (set.size() == pow(2, k));
    }
};