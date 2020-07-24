static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0, res=0, n=events.size();
        sort(events.begin(), events.end());
        
        for(int day=1; day <= 100000; day++)
        {
            
            while(pq.size() && pq.top() < day)
            {
                pq.pop();
            }
            
            while(i<n && events[i][0] == day)
            {
                pq.push(events[i][1]);
                i++;
            }
            
            if(pq.size())
            {
                res++;
                pq.pop();
            }
        }
        
        return res;
    }
};