static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

string Solution::multiple(int A) {
    
    if(A == 1)
        return  "1";
    
    queue<int> q;
    q.push(1);
    
    vector<int> parent(A, -1);
    vector<int> state(A, -1);
    vector<int> possiblities = {0, 1};
    
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        
        if(num == 0)
            break;
        
        for(int i=0; i<2; i++)
        {
            int curr = (num*10) + possiblities[i];
            curr %= A;
            
            if(parent[curr] == -1)
            {
                parent[curr] = num;
                state[curr] = i;
                q.push(curr);
            }
        }
    }
    
    deque<char> s;
    
    int temp = 0;
    
    while(temp != 1)
    {
        s.push_front('0' + state[temp]);
        temp = parent[temp];
    }
    
    s.push_front('1');
    
    return string(s.begin(), s.end());
}
