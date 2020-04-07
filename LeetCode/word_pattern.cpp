class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream ss(str);
        string s;
        vector<string> strings;
        
        while(ss >> s)  strings.push_back(s);
        
        if(pattern.size() != strings.size())    return false;
        
        map<char, string> cs;
        map<string, char> sc;
        
        for(int i=0; i<strings.size(); i++)
        {
            if(sc[strings[i]] == 0 && cs[pattern[i]] == "")
            {
                sc[strings[i]] = pattern[i];
                cs[pattern[i]] = strings[i];
                continue;
            }
            
            if(sc[strings[i]] != pattern[i])
                return false;
        }
        
        return true;
    }
};