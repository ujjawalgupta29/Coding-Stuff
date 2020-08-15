class Solution {
public:
    
    bool checkOverlap(vector<int> &curr, vector<int> &last)
    {
        if(last[1] > curr[0])
            return 1;
        
        return 0;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        if(n <= 1)
            return 0;
        
        int last = 0;
        int counts = 0;
        
        for(int curr=1; curr<n; curr++)
        {
            if(checkOverlap(intervals[curr], intervals[last]))
            {
                counts++;
                if(intervals[curr][1] < intervals[last][1])
                    last = curr;
            }
            else
            {
                last = curr;
            }
        }

        return counts;
    }
};