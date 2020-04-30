class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        vector<vector<int>> pal(len, vector<int>(len, 0));
        int counts = 0;
        
        for(int i=0; i< len; i++)
        {
            pal[i][i] = 1;
            counts++;
        }
        
        for(int i=0; i<len; i++)
        {
            int j=i+1;
            if(j < len && s[j] == s[i])
            {
                pal[i][j] = 1;
                counts++;
            }
        }
        
        for(int i=3; i<=len; i++)
        {
            for(int j=0; j<=len-i; j++)
            {
                if(s[j] == s[j+i-1] && pal[j+1][j+i-2] )
                {
                    pal[j][j+i-1] = 1;
                    counts++;
                }
            }
        }
        
        // for(int i=0; i<len; i++)
        // {
        //     for(int j=0; j<len; j++)
        //         cout << pal[i][j] << " ";
        //     cout << endl;
        // }
        
        return counts;
    }
};