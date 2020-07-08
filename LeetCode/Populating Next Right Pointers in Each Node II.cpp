static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(i < sz-1)
                    temp->next = q.front();                
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        return root;
    }
};