class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fav) {
        
        for(int i=0; i<fav.size(); i++)
            sort(fav[i].begin(), fav[i].end());
        
        vector<int> res;
        int n = fav.size();
        
        for(int i=0; i<n; i++)
        {
            bool check = 1;
            for(int j=0; j<n; j++)
            {
                if(j==i || fav[i].size() > fav[j].size())
                    continue;

                int idx1 = 0, idx2 = 0;
                while(idx1 < fav[i].size() && idx2 < fav[j].size())
                {
                    if(fav[i][idx1] == fav[j][idx2])
                    {
                        idx1++;
                        idx2++;
                    }
                    else if(fav[i][idx1] < fav[j][idx2])
                    {
                        break;
                    }
                    
                    else
                    {
                        idx2++;
                    }
                }
                if(idx1 == fav[i].size())
                {
                    check = 0;
                    break;
                }
            }
            if(check)
                res.push_back(i);
            
        }
        
        return res;
    }
};