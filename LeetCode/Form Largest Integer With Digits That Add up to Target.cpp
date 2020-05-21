static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        
        vector<string> mp(target+1, "");
        
        for(int i=1; i<=target; i++)
        {
            for(int c=0; c<9; c++)
            {
                string temp;
                if(cost[c] <= i)
                {
                    int temp_cost = cost[c];
                    int rem = i - temp_cost;
                    
                    if(rem == 0)
                    {
                        temp = to_string(c+1);
                    }
                    else
                    {
                        if(mp[rem] != "")
                        {
                            temp = to_string(c+1) + mp[rem];
                        }
                        else
                        {
                            temp = "";
                        }
                    }
                    
                    if(temp.size() > mp[i].size())
                        mp[i] = temp;
                    else if(temp.size() == mp[i].size())
                        mp[i] = (mp[i] > temp) ? mp[i] : temp;
                }
            }
            
        }
        
        return  (mp[target] == "") ? "0" : mp[target];
    }
};