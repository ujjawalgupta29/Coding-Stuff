class TrieNode {
public:
    vector<TrieNode*> next;
    bool is_end;
    TrieNode() {
        is_end = false;
        next = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();;

    Trie(vector<string> words) {
        for(int i=0; i<words.size(); i++) {
            addWord(root, words[i]);
        }
    }

    void addWord(TrieNode* root, string word) {
        int sz = word.size();
        TrieNode* curr = root;
        for(int i=0; i<sz; i++) {
            if(curr->next[word[i] - 'a'] == NULL) {
                curr->next[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->next[word[i] - 'a'];
        }
        curr->is_end = true;
    }
};


class Solution {
public:
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->root;
        
        int m = board.size();
        int n = board[0].size();
        
        set<string> result;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                checkWords(board, root, result, "", i, j, m, n);
            }
        }
        
        vector<string> res;
        for(string s : result) {
            res.push_back(s);
        }
        
        return res;
    }
    
    void checkWords(vector<vector<char>>& board, TrieNode* root, set<string> &result, string word,
                   int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == ' ')
            return;
        
        if(root->next[board[x][y] - 'a'] != NULL) {
            char ch = board[x][y];
            word += board[x][y];
            board[x][y] = ' ';
            root = root->next[ch - 'a'];
            if(root->is_end) {
                result.insert(word);
                // return;
            }
            checkWords(board, root, result, word, x+1, y, m, n);
            checkWords(board, root, result, word, x, y+1, m, n);
            checkWords(board, root, result, word, x, y-1, m, n);
            checkWords(board, root, result, word, x-1, y, m, n);
            
            board[x][y] = ch;
        }
    }
    
};