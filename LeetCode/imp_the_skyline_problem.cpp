//multiset

bool compare(vector<int>& v1, vector<int> &v2)
{
    if(v1[0] != v2[0])
        return v1[0] < v2[0];
    
    else if(v1[2] && v2[2])
        return v1[1] > v2[1];
    
    else if(!v1[2] && !v2[2])
        return v1[1] < v2[1];
    
    else
        return v1[2]==1;
}

class Solution {
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> coordinates;
        vector<vector<int>> res;
        for(auto b : buildings)
        {
            coordinates.push_back({b[0], b[2], 1});
            coordinates.push_back({b[1], b[2], 0});
        }
        
        sort(coordinates.begin(), coordinates.end(), compare);
        
        multiset<int, greater<int>> height;
        height.insert(0);
        
        int prevMaxHt = 0;
        
        for(auto c : coordinates)
        {
            if(c[2])
            {
                height.insert(c[1]);
            }
            
            else
            {
                auto it = height.find(c[1]);
                if(it != height.end())
                    height.erase(it);
            }
            
            int currMaxHt = *height.begin();
            
            if(prevMaxHt != currMaxHt)
            {
                res.push_back({c[0], currMaxHt});
                prevMaxHt = currMaxHt;
            }
        }
        
        return res;
    }
};



//using map & priority_queue


bool compare(vector<int>& v1, vector<int> &v2)
{
    if(v1[0] != v2[0])
        return v1[0] < v2[0];
    
    else if(v1[2] && v2[2])
        return v1[1] > v2[1];
    
    else if(!v1[2] && !v2[2])
        return v1[1] < v2[1];
    
    else
        return v1[2]==1;
}

class Solution {
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> coordinates;
        vector<vector<int>> res;
        for(auto b : buildings)
        {
            coordinates.push_back({b[0], b[2], 1});
            coordinates.push_back({b[1], b[2], 0});
        }
        
        sort(coordinates.begin(), coordinates.end(), compare);
        
        map<int, int> mp;
        priority_queue<int> height;
        height.push(0);
        mp[0] = 1;
        
        int prevMaxHt = 0;
        
        for(auto c : coordinates)
        {
            if(c[2])
            {
                mp[c[1]]++;
                height.push(c[1]);
            }
            
            else
            {
                mp[c[1]]--;
            }
            
            int top = height.top();
            int currMaxHt = -1;
            
            while(currMaxHt == -1)
            {
                // cout << top << " " << mp[top] << endl;
                if(mp[top] > 0)
                    currMaxHt = top;
                else
                {
                    height.pop();
                    top = height.top();
                }
            }
            
            
            if(prevMaxHt != currMaxHt)
            {
                res.push_back({c[0], currMaxHt});
                prevMaxHt = currMaxHt;
            }
        }
        
        return res;
    }
};