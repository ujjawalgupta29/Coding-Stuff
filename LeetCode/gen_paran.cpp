class Solution {
public:
    
    void generate(vector<string> &res, int idx, int left, int right, string temp)
    {
        if(left < 0 || right < 0 || right < left)
            return;
        if(left == 0 && right == 0)
        {
            res.push_back(temp);
            return;
        }
        
        temp[idx] = '(';
        generate(res, idx+1, left-1, right, temp);
        
        temp[idx] = ')';
        generate(res, idx+1, left, right-1, temp);
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp(n*2, ' ');
        generate(res, 0, n, n, temp);
        return res;
    }
};