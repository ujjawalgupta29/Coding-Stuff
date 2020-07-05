class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> curr(8);
        for(int i=0; i<N; i++)
        {
            for(int i=1; i<7; i++)
            {
                curr[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
            }
            if(curr == cells)
                return curr;
            cells = curr;
        }
        
        return cells;
    }
};