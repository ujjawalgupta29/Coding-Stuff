class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> list(num);
        vector<int> degrees(num);
        vector<int> res;
        
        for(int i=0; i<pre.size(); i++)
        {
            list[pre[i][1]].push_back(pre[i][0]);
            degrees[pre[i][0]]++;
        }
        
        stack<int> zero_deg;
        
        for(int i=0; i<degrees.size(); i++)
        {
            if(degrees[i] == 0)
                zero_deg.push(i);
        }
        
        while(!zero_deg.empty())
        {
            int node = zero_deg.top();
            zero_deg.pop();
            res.push_back(node);
            
            for(int i=0; i<list[node].size(); i++)
            {
                degrees[list[node][i]]--;
                if(degrees[list[node][i]] == 0)
                    zero_deg.push(list[node][i]);
            }
        }
        
        return (res.size() == num) ? res : vector<int>();
    }
};