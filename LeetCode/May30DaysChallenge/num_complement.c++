class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
        
        string s;
        
        while(num != 0)
        {
            if(num % 2 == 0)
                s += '1';
            else
                s += '0';
            num = num / 2;
        }
        
        int sum = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '1')
                sum += pow(2, i);
        }

        return sum;
    }
};