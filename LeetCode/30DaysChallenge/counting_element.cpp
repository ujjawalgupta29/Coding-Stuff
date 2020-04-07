class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> mp;
        
        if(arr.size() < 2)
            return 0;
        
        for(int x : arr)
        {
            mp[x]++;
        }
        
        auto prev = mp.begin();
        int counts = 0;
        auto curr = mp.begin();
        curr++;
        
        for(    ; curr != mp.end(); curr++)
        {
            if(curr->first == prev->first + 1)
            {
                counts += prev->second;
            }
            prev = curr;
        }
        
        return counts;
        
    }
};