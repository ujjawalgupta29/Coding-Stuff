class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size(); 
        vector<int> res;
        
        vector<int> idx(26);
        
        for(int i=0; i<len; i++)
            idx[s[i]-'a'] = i;
        
        int prev = -1;
        int  max_last = 0;
        for(int i=0; i<len; i++)
        {
            max_last = max(max_last, idx[s[i]-'a']);
            
            if(max_last == i)
            {
                res.push_back(i-prev);
                prev = i;
            }
        }
        
        return res;
    }
};