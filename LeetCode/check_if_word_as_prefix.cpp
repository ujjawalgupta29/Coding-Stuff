class Solution {
public:
    int isPrefixOfWord(string sentence, string srch) {
        stringstream ss(sentence);
        vector<string> words;
        string temp;
        
        while(ss >> temp)
            words.push_back(temp);
        
        int idx = -1;
        
        for(int i=0; i<words.size(); i++)
        {
            int temp_idx = words[i].find(srch);    
            if( (temp_idx != string :: npos) && temp_idx == 0 )
            {
                idx = i+1;
               break; 
            }
        }
        
        return idx;
    }
};