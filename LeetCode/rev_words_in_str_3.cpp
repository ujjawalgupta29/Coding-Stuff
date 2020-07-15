class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        
        string word;
        string res;
        while(ss >> word)
        {
            reverse(word.begin(), word.end());
            res += word;
            res += ' ';
        }
        
        int len = res.size();
        return res.substr(0, len-1);
    }
};