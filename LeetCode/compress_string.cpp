class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int i=0, j=0;
        char ch;
        
        for(int i=0; i<n; i++)
        {
            char ch = chars[i];
            i++;
            int counts = 1;
            while(i < n && chars[i] == ch)
            {
                i++;
                counts++;
            }
            i--;
            
            chars[j] = ch;
            j++;
            if(counts > 1)
            {
                string num = to_string(counts);
                for(int k=0; k<num.size(); k++)
                {
                    chars[j] = num[k];
                    j++;
                }
            }
        }
        
        return j;
    }
};