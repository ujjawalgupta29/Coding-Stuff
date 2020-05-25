class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        
        for(int d=1; d<=n; d++)
        {
            for(int num = 1; num < d; num++)
            {
                if(__gcd(d, num) == 1)
                {
                    string s = to_string(num) + "/" + to_string(d);
                    res.push_back(s);
                }
            }
        }
        
        return res;
    }
};