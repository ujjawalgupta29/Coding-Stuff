class Solution {
public:
    
    int build(vector<int> digits)
    {
        int n = digits.size();
        int num = 0;
        
        for(int i=0; i<n; i++)
        {
            num = num*10 + digits[i];
        }
        
        return num;
    }
    
    int find_first_min(vector<int> digits, int num)
    {
        int i;
        for(i=0; i<digits.size(); i++)
        {
            if(digits[i] != num && (digits[i] != 0))
                break;
        }
        
        return i;
    }
    
    int find_first_max(vector<int> digits, int num)
    {
        int i;
        for(i=0; i<digits.size(); i++)
        {
            if(digits[i] != num)
                break;
        }
        
        return i;
    }
    
    int build_max(vector<int> digits)
    {
        int n = digits.size();
        int idx = find_first_max(digits, 9);
        // cout << "max_idx = " << idx << endl;
        if(idx < n)
        {
            int dig = digits[idx];
            for(int i=0; i<n; i++)
            {
                if(digits[i] == dig)
                    digits[i] = 9;
            }
        }
        // for(int x : digits)
        //     cout << x;
        // cout<<endl;
        
        return build(digits);
    }
    
    int build_min(vector<int> digits)
    {
        int n = digits.size();
        int idx = find_first_min(digits, 1);
        if(idx < n)
        {
            int dig = digits[idx];
            int number = (idx == 0) ? 1 : 0;
            for(int i=0; i<n; i++)
            {
                if(digits[i] == dig)
                    digits[i] = number;
            }
        }
        
        return build(digits);
    }
    
    int maxDiff(int num) {
        vector<int> digits;
        while(num != 0)
        {
            digits.push_back(num%10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        // cout << "initial digits : " ;
        // for(int x : digits)
        //     cout << x;
        // cout << endl;
        
        vector<int> max_num = digits;
        vector<int> min_num = digits;
        
        int max_number = build_max(max_num);
        int min_number = build_min(min_num);
        
        // cout << max_number << " " << min_number << endl;
        
        return max_number - min_number;
    }
};