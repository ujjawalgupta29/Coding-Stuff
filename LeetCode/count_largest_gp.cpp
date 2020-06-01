class Solution {
public:
    
    int sum(int x)
    {
        int counts = 0;
        while(x != 0)
        {
            counts += x%10;
            x = x/10;
        }
        return counts;
    }
    
    int countLargestGroup(int n) {
        int max_len = 0;
        unordered_map<int, int> mp;
        
        for(int i=1; i<=n; i++)
        {
            int temp = sum(i);
            mp[temp]++;
            max_len = max(max_len, mp[temp]);
        }
        
        int total = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == max_len)
                total++;
        }
        
        return total;
    }
};