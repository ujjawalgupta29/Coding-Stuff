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
        
        string res;
        res = to_string(root->val) + ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {
        queue<string> values = generate(data);
        return build(values);
    }
    
    TreeNode* build(queue<string> &values)
    {
        string temp = values.front();
        values.pop();
        
        if(temp == "X")
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(temp));
        
        root->left = build(values);
        root->right = build(values);
        
        return root;
    }
    
    queue<string> generate(string data)
    {
        int len = data.size();
        int i = 0;
        queue<string> res;
        
        while(i < len)
        {
            string temp;
            if(data[i] == 'X')
            {
                res.push("X");
                i += 2;
            }
            
            else if(data[i] == ',')
                i++;
            
            else
            {
                while(i < len && data[i] != ',')
                {
                    temp+= data[i];
                    i++;
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