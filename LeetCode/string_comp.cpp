class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        int cons = 0;
        int idx = 0;
        for(int i=0; i<len; i++)
        {
            cons++;
            if((i == len - 1 || chars[i] != chars[i+1]))
            {
                chars[idx++] = chars[i];
                string temp = to_string(cons);
                if(cons > 1)
                {
                    for(int j=0; j<temp.size(); j++)
                        chars[idx++] = temp[j];
                }
                cons = 0;
            }
        }
        
        return idx;
    }
};