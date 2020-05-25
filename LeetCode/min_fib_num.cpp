class Solution {
public:
    
    int search(vector<int>fib, int l, int r, int x)
    {
        while(l <= r)
        {
            int mid = (l+r)/2;
            
            if(fib[mid] == x)
                return mid;
            
            else if(fib[mid] < x)
                l = mid + 1;
            
            else
                r = mid - 1;
        }
        
        return r;
    }
    
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        
        for(int i=2; i<45; i++)
        {
            if(fib[i-1] + fib[i-2] > INT_MAX)
                break;
            fib.push_back(fib[i-1] + fib[i-2]);
        }
        
        int n = fib.size();
        int counts = 0;
        while(k > 0)
        {
            int idx = search(fib, 0, fib.size()-1, k);
            k = k - fib[idx];
            counts++;
        }
        return counts;
    }
};