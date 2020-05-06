bool operator < (vector<int> &v, int a)
{
    for(int x : v)
        if(x < a)
            return 1;
    return 0;
}

void operator +=(vector<int> &a, vector<int> &b)
{
    for(int i=0; i<a.size(); i++)
        a[i] += b[i];
}

void operator -=(vector<int> &a, vector<int> &b)
{
    for(int i=0; i<a.size(); i++)
        a[i] -= b[i];
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> mp;
        return helper(price, special, needs, mp, 0);
    }
    
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,
                       unordered_map<int, int> mp, int cost) {
        if(needs < 0)
            return INT_MAX;
        
        int key = get_key(needs);
        if(mp.find(key) != mp.end())
            return mp[key]; 
        
        int m = inner_product(price.begin(), price.end(), needs.begin(), cost);
            
        for(auto offer : special)
        {
            if(cost + offer.back() >= m)
                continue;
            
            needs -= offer;
            m = min(m, helper(price, special, needs, mp, cost+offer.back()));
            needs += offer;
        }
        
        mp[key] = m;
        
        return m;
    }
    
    int get_key(vector<int>& needs) 
    {
        int n = needs.size(), key = 0;
        for (int i = n-1, p = 1; i >= 0; i--, p *= 10)
            key += needs[i]*p;
        return key;
    }
};