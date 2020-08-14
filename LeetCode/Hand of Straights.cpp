static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int w) {
        int n = hand.size();
        
        if(n % w != 0)
            return 0;
        
        map<int, int> mp;
        for(int x : hand)
            mp[x]++;
        
        if(mp.size() < w)
            return 0;
        
        int count = n / w;
        
        while(count != 0)
        {
            auto it = mp.begin();
            
            int num = it->first;
            int i;
            for(i=0; i<w; i++)
            {
                // cout << it->first <<  " " << mp[it->first] <<" " << num << endl;
                if(it->first == num)
                {
                    mp[it->first]--;
                    auto temp = it;
                    if(mp[it->first] == 0)
                    {
                        mp.erase(it->first);
                    }
                    it = temp;
                    it++;
                    num++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            if(i == w)
                count--;
            else
                break;
        }
        
        return count == 0;
    }
};