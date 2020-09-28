class Solution {
public:
    vector<vector<int>> coordi;
    vector<int> areaSum;
    int n;
    Solution(vector<vector<int>>& rects) {
        coordi = rects;
        n = coordi.size();
        int sum = 0;
        for(auto v : coordi)
        {
            sum += (v[2]-v[0]+1)*(v[3]-v[1]+1);
            areaSum.push_back(sum);
        }
    }
    
    vector<int> pick() {
        int rnd_idx = rand() % areaSum.back();
        int idx = upper_bound(areaSum.begin(), areaSum.end(), rnd_idx) - areaSum.begin();
        auto r = coordi[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        
        return vector<int>{x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */