class TrieNode {
public:

    TrieNode* next[26];
    bool endWord;
    
    TrieNode() {
        memset(next, 0, sizeof(next));
        endWord = false;
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
public:
    Trie() {
        root  = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        TrieNode *p = root;
        for(int i=0; i<s.length(); i++)
        {
            if(p->next[s[i] - 'a'] == NULL)
            {
                p->next[s[i] - 'a'] = new TrieNode();
            }
            p = p->next[s[i] - 'a'];
        }
        p->endWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
        TrieNode *p =root;
        for(int i=0; i<s.length(); i++)
        {
            if(p->next[s[i] - 'a'] == NULL)
            {
                return false;
            }
            p = p->next[s[i] - 'a'];
        }
        if(p->endWord)
            return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        TrieNode *p =root;
        for(int i=0; i<s.length(); i++)
        {
            if(p->next[s[i] - 'a'] == NULL)
            {
                return false;
            }
            p = p->next[s[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */