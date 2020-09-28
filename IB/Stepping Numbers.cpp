vector<int> ans;

void dfs(int len, int A, int B, int num=0)
{
    if(num >= A && num<= B)
        ans.push_back(num);    
        
    if(len == 0)
        return;
        
    if(num == 0)
    {
        for(int i=1; i<=9; i++)
        {
            dfs(len, A, B, i);
        }
        
        return;
    }
    
    
    int last_digit = num%10;
    
    if(last_digit == 0)
    {
        dfs(len-1, A, B, num*10 + 1);
    }
    
    else if(last_digit == 9)
    {
        dfs(len-1, A, B, num*10 + 8);
    }
    
    else
    {
        dfs(len-1, A, B, num*10 + (last_digit-1));
        dfs(len-1, A, B, num*10 + (last_digit+1));
    }
}

vector<int> Solution::stepnum(int A, int B) {
    
    ans.clear();
    
    int len = 0;
    int temp = B;
    
    while(temp > 0)
    {
        temp /= 10;
        len++;
    }
    
    dfs(len, A, B);
    sort(ans.begin(), ans.end());
    return ans;
}
