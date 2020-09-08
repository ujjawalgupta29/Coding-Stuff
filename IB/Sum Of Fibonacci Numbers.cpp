int Solution::fibsum(int A) {
    vector<int> fib;
    
    int a=1;
    int b=1;
    
    fib.push_back(1);
    fib.push_back(1);
    int c = a+b;
    
    while(c <= A)
    {
        fib.push_back(c);
        a = b;
        b = c;
        c = a+b;
    }
    
    int len = fib.size();
    int counts = 0;
    
    for(int i=len-1; i>=0; i--)
    {
        if(fib[i] <= A)
        {
            counts += A / fib[i];
            A = A - fib[i] * (A/fib[i]);
        }
    }
    
    return counts;
}
