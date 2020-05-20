class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> index(m, 0);
        vector<int> res;
        
        for(int i=0; i<queries.size(); i++)
        {
            int num = queries[i];
            int temp = num-1 + index[num-1];
            res.push_back(temp);
            
            index[num-1] -= temp;
            int val = temp;
            
            for(int j=0; j<m; j++)
            {
                if(j != num-1  && j + index[j] <= val)
                {
                    index[j] += 1;
                }
            }
        }
        
        return res;
    }
};