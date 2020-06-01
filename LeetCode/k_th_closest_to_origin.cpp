class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(),[](
            vector<int> &v1, vector<int> &v2)
                    {
                        return v1[0]*v1[0] + v1[1]*v1[1] < v2[0]*v2[0] + v2[1]*v2[1];
                    });
        points.resize(K);
        
        return points;
    }
};