class Solution {
public:
    int busyStudent(vector<int>& st, vector<int>& et, int q) {
        int n = st.size();
        int counts = 0;
        
        for(int i=0; i<n; i++)
        {
            if(q >= st[i] && q <= et[i])
                counts++;
        }
        
        return counts;
    }
};