class Solution {
public:

    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> pallindrome(len, vector<bool>(len, 0));
        
        for(int i=0; i<len; i++)
        {
            pallindrome[i][i] = 1;
        }
        
        for(int length = 2; length <= len; length++)
        {
            for(int start = 0; start <= len - length ; start++)
            {
                int end = start + length -1;
                if(length == 2)
                {
                    pallindrome[start][end] = (s[end] == s[start]);
                }
                else
                {
                    pallindrome[start][end] = (s[end] == s[start] && pallindrome[start+1][end-1]);
                }
            }
        }
        
        vector<int> min_cuts(len);
        
        for(int i=0; i<len; i++)
        {
            if(pallindrome[0][i])
                min_cuts[i] = 0;
            
            else
            {
                min_cuts[i] = min_cuts[i-1] + 1;
                for(int j = 0; j<i; j++)
                {
                    if(pallindrome[j][i] && min_cuts[j-1] + 1 < min_cuts[i])
                        min_cuts[i] = min_cuts[j-1] + 1;
                }
            }
        }
        
        return min_cuts[len-1];
    }
};