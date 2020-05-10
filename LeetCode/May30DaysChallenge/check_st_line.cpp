class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordi) {
        int len = coordi.size();
        if(len == 2)
            return 1;
        
        double slope = (double)(coordi[1][1] - coordi[0][1]) / (coordi[1][0] - coordi[0][0]);
        double c = (double)(coordi[0][1] - slope * coordi[0][0]);
        
        for(int i=2; i<len; i++)
        {
            double temp = (double)(coordi[i][1] - slope * coordi[i][0]);
            if(temp != c)
                return 0;
        }
        
        return 1;
    }
};