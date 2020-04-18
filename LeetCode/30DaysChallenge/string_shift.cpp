class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        deque<char> str(s.begin(), s.end());
        int m = shift.size();
        int counts = 0;
        for(int i=0; i<m; i++)
        {
            if(shift[i][0])
                counts += shift[i][1];
            else
                counts -= shift[i][1];
        }
        
        if(counts > 0)
        {
            counts = counts % (s.length());
            while(counts--)
            {
                char ch = str.back();
                str.pop_back();
                str.push_front(ch);
            }
        }
        
        else
        {
            counts = abs(counts);
            counts = counts % (s.length());
            while(counts--)
            {
                char ch = str.front();
                str.pop_front();
                str.push_back(ch);
            }
        }
        
        return string(str.begin(), str.end());
    }
};