class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> idx(26, vector<int>(2, -1));
        int len = s.size();
        
        for(int i=0; i<len; i++)
        {
            char c = s[i];
            int val = int(c - 'a');
            if(idx[val][0] == -1)
            {
                idx[val][0] = idx[val][1] = i;
            }
            else
            {
                idx[val][1] = i;
            }
        }
        
        sort(idx.begin(), idx.end(), [](const vector<int> &v1, const vector<int> &v2) {
            if(v1[0] != v2[0])
                return v1[0] < v2[0];
            else
                return v1[1] < v2[1];
        });
        
        vector<int> res;
        vector<vector<int>> temp;
        
        for(auto v : idx)
        {
            if(v[0] == -1)
                continue;
            if(temp.size() == 0)
                temp.push_back(v);
            else
            {
                int last = temp.size()-1;
                if(v[1] <= temp[last][1])
                    continue;
                else if(v[0] >= temp[last][1] )
                    temp.push_back(v);
                else if(v[1] > temp[last][1])
                    temp[last][1] = v[1];
            }
        }
        
        for(auto v : temp)
        {
            res.push_back(v[1] - v[0] + 1);
        }
        
        return res;
    }
};