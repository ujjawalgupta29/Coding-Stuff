class Solution {
public:
    
    class alphabet
    {
        public:
        
        char ch;
        int freq;
        
        alphabet()
        {
            freq = 0;
        }
    };
    
    string frequencySort(string s) {
        alphabet A[256];
        for(int i=0; i<s.size(); i++)
        {
            A[s[i]].ch = s[i];
            A[s[i]].freq++;
        }
        
        sort(A, A+256, [](const alphabet &A1, const alphabet &A2)
             {
                 return A1.freq > A2.freq;
             });
        
        string res;
        for(int i=0; i<256; i++)
        {
            res += string(A[i].freq, A[i].ch);
        }
        
        return res;
    }
};