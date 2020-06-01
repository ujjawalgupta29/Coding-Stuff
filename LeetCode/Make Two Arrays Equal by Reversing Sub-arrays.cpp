class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> counts(1001, 0);
        
        for(int x : target)
            counts[x]++;
        
        for(int i=0; i<target.size(); i++)
        {
            counts[arr[i]]--;
            if(counts[arr[i]] < 0)
                return 0;
        }
        
        for(int i=0; i<1001; i++)
        {
            if(counts[i] != 0)
                return 0;
        }
        
        return 1;
    }
};