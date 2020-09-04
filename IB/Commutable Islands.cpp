bool compare(const vector<int> &v1, const vector<int> &v2)
{
    return v1[2] < v2[2];
}

int find(int node, vector<int> &parent)
{
    if(parent[node] == node)
        return node;
        
    return find(parent[node], parent);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), compare);
    
    vector<int> parent(A+1);
    for(int i=0; i<A+1; i++)
        parent[i] = i;
        
    int cost = 0;
    
    for(int i=0; i<B.size(); i++)
    {
        int x = B[i][0];
        int y = B[i][1];
        
        int parent1 = find(x, parent);
        int parent2 = find(y, parent);
        
        if(parent1 != parent2)
        {
            cost += B[i][2];
            parent[parent1] = parent2;
        }
    }
    
    return cost;
}
