static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    void dfs(Node* node, Node* new_head, unordered_map<Node*, Node*> &mp,
            unordered_set<Node*> &visited)
    {
        if(node->neighbors.size() == 0)
            return;
        
        visited.insert(node);
        
        for(auto it = node->neighbors.begin(); it != node->neighbors.end(); it++)
        {
            if(mp.find(*it) == mp.end())
            {
                Node* new_node = new Node((*it)->val);
                mp[*it] = new_node;
            }
            
            new_head->neighbors.push_back(mp[*it]);
            
            if(visited.find(*it) == visited.end())
                dfs(*it, mp[*it], mp, visited);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        
        unordered_map<Node*, Node*> mp;
        Node* new_head = new Node(1);
        mp[node] = new_head;
        unordered_set<Node*> visited;
        dfs(node, new_head, mp, visited);
        return new_head;
    }
};