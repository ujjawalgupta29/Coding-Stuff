class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        
        unordered_map<int, int> mp;
        int count = 0;
        
        for(auto clip : clips)
        {
            mp[clip[0]] = max(mp[clip[0]], clip[1]);
        }
        
        int selectedEnd = -1, reachableEnd = 0;
        
        for(int i=0; i<=T; i++)
        {
            if(reachableEnd >= T || i > reachableEnd)
                break;
            
            if(mp.count(i))
            {
                if(i > selectedEnd)
                {
                    count++;
                    selectedEnd = reachableEnd;
                }
                reachableEnd = max(reachableEnd, mp[i]);
            }
        }
        
        return (reachableEnd >= T) ? count : -1;
    }
};