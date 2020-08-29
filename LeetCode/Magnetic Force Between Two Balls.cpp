class Solution {
public:
    
    bool check(vector<int> &pos, int mid, int m)
    {
        m = m-1; 
        int prev = pos[0];
        
        for(int i=1; i<pos.size(); i++)
        {
            if(pos[i] - prev >= mid)
            {
                m--;
                prev = pos[i];
            }
            
            if(m == 0)
                return 1;
        }
        
        return false;
        
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        
        int low = 1;
        sort(position.begin(), position.end());
        int high = position[n-1];
        
        while(low < high)
        {
            int mid = (low + high + 1) / 2;
            
            if(check(position, mid, m))
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
};