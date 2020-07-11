int Solution::solve(vector<int> &A) {
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(int x : A)
    {
        q.push(x);
    }
    
    int cost = 0;
    while(q.size() > 1)
    {
        int a = q.top();
        q.pop();
        
        int b = q.top();
        q.pop();
        
        cost += a + b;
        q.push(a+b);
    }
    
    return cost;
}
