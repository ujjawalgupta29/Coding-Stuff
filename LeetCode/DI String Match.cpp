class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        int countD = 0;
        for(int i=0; i<s.size(); i++)
        {
            countD += (s[i] == 'D');
        }
        
        vector<int> res{countD};
        int countI = countD;
        
        for(int i=0; i<s.size(); i++)
        {
            res.push_back(s[i] == 'D' ? --countD : ++countI);
        }
        
        return res;
    }
};