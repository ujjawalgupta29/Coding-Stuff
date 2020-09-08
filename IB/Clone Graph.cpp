/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    mp[node] = root;
    
    queue<UndirectedGraphNode*> q;
    q.push(node);
    
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        auto curr_node = mp[top];
        
        for(auto it=top->neighbors.begin(); it != top->neighbors.end(); it++)
        {
            if(mp.find(*it) == mp.end())
            {
                UndirectedGraphNode* temp = new UndirectedGraphNode((*it)->label);
                mp[*it] = temp;
                q.push(*it);
            }
            curr_node->neighbors.push_back(mp[*it]);
        }
    }
    
    return root;
}
