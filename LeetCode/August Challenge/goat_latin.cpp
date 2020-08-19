class Solution {
public:
    string toGoatLatin(string s) {
        string res;
        stringstream ss(s);
        int counts = 1;
        
        string temp;
        
        while(ss >> temp)
        {
            if(temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u'
               || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U')
            {
                res += " " +  temp + "ma" + string(counts, 'a');
            }
            
            else
            {
                res += " " + temp.substr(1) + temp[0] + "ma" + string(counts, 'a');
            }
            
            counts++;
        }
        
        return res.substr(1);
    }
};