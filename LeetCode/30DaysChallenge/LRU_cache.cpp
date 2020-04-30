class LRUCache {
public:
    list<int> LRU;
    unordered_map<int, pair<int, list<int>::iterator >> ump;
    int cap;
    
    LRUCache(int capacity) {
        this->cap = capacity;    
    }
    
    int get(int key) {
        auto it = ump.find(key);
        
        if(it == ump.end())
            return -1;
        
        update(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = ump.find(key);
        
        if(it != ump.end())
        {
            update(it);
        }
        else
        {
            if(ump.size() == cap)
            {
                ump.erase(LRU.back());
                LRU.pop_back();
            }
            LRU.push_front(key);
        }
        ump[key] = make_pair(value, LRU.begin());
    }
    
    void update(unordered_map<int, pair<int, list<int>::iterator >>::iterator it)
    {
        int key = it->first;
        LRU.erase(it->second.second);
        LRU.push_front(key);
        it->second.second = LRU.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */     