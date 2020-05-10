class Solution {
public:
    string reverseWords(string s) {
        
        if(s == "")
            return s;
        
        int start = 0;
        int end = s.length() - 1;
        
        while(start < s.length() && s[start] == ' ')
            start++;
        while(end > start && s[end] == ' ')
            end--;
        s = s.substr(start, end - start + 1);
        
        stringstream str(s);
        
        string word;
        string res = "";
        stack<string> temp;
        while(str >> word)
        {
            temp.push(word);
        }
        

        
        while(!temp.empty())
        {
            res += temp.top();
            temp.pop();
            
            if(temp.size() > 0)
                res += ' ';
        }
        
        return res;
    }
};