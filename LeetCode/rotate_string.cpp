class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size())
            return 0;
        
        string res = A + A;
        int pos = res.find(B);
        if(pos != string::npos)
            return 1;
        
        return 0;
    }
};