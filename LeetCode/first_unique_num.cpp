class FirstUnique {
public:
    list <int> unique;
    unordered_map<int, list<int> :: iterator>  mp;
    
    FirstUnique(vector<int>& nums) {
        for(int x : nums)
        {
            add(x);
        }
    }
    
    int showFirstUnique() {
        return unique.empty() ? -1 : unique.front();
    }
    
    void add(int value) {
        if(!mp.count(value))
        {
            unique.push_back(value);
            mp[value] = --unique.end();
        }
        
        else if(mp[value] != unique.end())
        {
            unique.erase(mp[value]);
            mp[value] = unique.end(); 
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */