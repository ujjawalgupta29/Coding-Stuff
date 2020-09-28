class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        
        if(dead.find("0000") == dead.end())
        {
            q.push({"0000", 0});
            visited.insert("0000");   
        }
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            
            string s = top.first;
            // cout << s << endl;
            int counts = top.second;
            
            if(s == target)
                return top.second;
            
            for(int i=0; i<4; i++)
            {
                string temp1 = s;
                temp1[i] = ((s[i] - '0' + 1)%10) + '0';
                
                string temp2 = s;
                temp2[i] = ((s[i] - '0' - 1 + 10)%10) + '0';
                
                if(dead.find(temp1) == dead.end() && visited.find(temp1) == visited.end())
                {
                    q.push({temp1, counts+1});
                    visited.insert(temp1);
                }
                
                if(dead.find(temp2) == dead.end() && visited.find(temp2) == visited.end())
                {
                    q.push({temp2, counts+1});
                    visited.insert(temp2);
                }
                    
            }
        }
        
        return -1;
    }
};