/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "X,";
        
        string res = "";
        
        res += to_string(root->val);
        res += ',';
        res += serialize(root->left);
        res += serialize(root->right);
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> values = extract_values(data);
        return build(values);
    }
    
    
    TreeNode* build(queue<string>& values)
    {
        string val = values.front();
        values.pop();
        
        if(val == "X")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(values);
        root->right = build(values);
        
        return root;
    }
    
    queue<string> extract_values(string data)
    {
        int len = data.size();
        int idx = 0;
        queue<string> res;
        
        while(idx < len)
        {
            if(data[idx] == ',')
                idx++;
            
            else if(data[idx] == 'X')
            {
                res.push("X");
                idx += 2;
            }
            
            else
            {
                string temp = "";
                while(idx < len && data[idx] != ',' )
                {
                    temp += data[idx];
                    idx++;
                }
                res.push(temp);
            }
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));