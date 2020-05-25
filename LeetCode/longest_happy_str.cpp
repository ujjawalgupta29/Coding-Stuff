class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int count_a = 0, count_b = 0, count_c = 0;
        
        string res;
        int len = a+b+c;
        for(int i=0; i<len; i++)
        {
            if( (a>=b && a>=c && count_a != 2) || (count_b==2 && a>0) || (count_c==2 && a > 0) )
            {
                res.push_back('a');
                count_a++;
                a--;
                count_b=0;
                count_c=0;
            }
            
            else if( (b>=a && b>=c && count_b != 2) || (count_a==2 && b>0) || (count_c==2 && b > 0) )
            {
                res.push_back('b');
                count_b++;
                b--;
                count_a=0;
                count_c=0;
            }
            
            else if( (c>=b && c>=a && count_c != 2) || (count_b==2 && c>0) || (count_a==2 && c > 0) )
            {
                res.push_back('c');
                count_c++;
                c--;
                count_a=0;
                count_b=0;
            }
            
            else
                break;
        }
        
        return res;
    }
};