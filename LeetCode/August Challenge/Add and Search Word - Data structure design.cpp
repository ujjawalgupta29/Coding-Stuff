class TrieNode {
    public:
    char ch;
    TrieNode* next[26];
    bool finish = false;
    
    TrieNode()
    {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
        TrieNode* root;
        
        public:
        
        Trie()
        {
            root = new TrieNode();    
        }
        
        void insert(string s)
        {
            TrieNode* temp = root;
            for(int i=0; i<s.size(); i++)
            {
                if(temp->next[s[i] - 'a'] == NULL)
                {
                    temp->next[s[i] - 'a'] = new TrieNode();
                }
                temp = temp->next[s[i] - 'a'];
            }
            
            temp->finish = true;
        }
        
        bool search(string s)
        {
            return search_helper(s, 0, root);
        }
    
        bool search_helper(string s, int idx, TrieNode* root)
        {
            if(idx == s.size() && root->finish == true)
                return true;
            
            if(idx == s.size())
                return false;
            
            if(s[idx] != '.' && root->next[s[idx] - 'a'] == NULL)
                return false;
            
            if(s[idx] == '.')
            {
                bool exist = false;
                for(int i=0; i<26; i++)
                {
                    if(root->next[i])
                    {
                        exist |= search_helper(s, idx+1, root->next[i]);
                        if(exist)
                            break;   
                    }
                }
                
                return exist;
            }
            
            else
                return search_helper(s, idx+1, root->next[s[idx] - 'a']);
        }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* trie = new Trie();
    
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->search(word);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */