class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0;
        int capital = 0;
        bool flag = (word[0] >= 'A' && word[0] <= 'Z');
        
        for(char ch : word)
        {
            if(ch >= 'A' && ch <= 'Z')
                capital++;
            else
                small++;
        }
        
        return (capital == 1 && flag) || (capital == 0) || (capital == word.size());
    }
};