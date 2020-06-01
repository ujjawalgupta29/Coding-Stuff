static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class UndergroundSystem {
public:
    unordered_map<string, unordered_map<string, pair<int, int>> > mp;
    unordered_map<int, pair<string, int> > person;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        person[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string dest = stationName;
        string start = person[id].first;
        mp[start][dest].first += t - person[id].second;
        mp[start][dest].second++;
    }
    
    double getAverageTime(string start, string dest) {
        return double(mp[start][dest].first) /  double(mp[start][dest].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */