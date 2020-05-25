class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int sz = target.size();
        int idx = 0;
        int counter = 1;
        
        while(idx < sz)
        {
            res.push_back("Push");
            if(target[idx] == counter)
            {
                idx++;
                counter++;
                continue;
            }
            
            else
            {
                res.push_back("Pop");
                counter++;
            }
            
        }
        
        return res;
        
    }
};