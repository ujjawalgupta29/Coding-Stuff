#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class TrieNode
{
public:
    TrieNode* next[26];
    bool endword;

    TrieNode()
    {
        memset(next, 0, sizeof(next));
        endword = 0;
    }
};

class Trie
{
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode* ptr = this->root;
        ifor(i, 0, s.length())
        {
            if(ptr->next[s[i] - 'a'] == NULL)
            {
                ptr->next[s[i] - 'a'] = new TrieNode();
            }
            ptr = ptr->next[s[i] - 'a'];
        }
        ptr->endword = true;
    }

    bool search_string(string s)
    {
        TrieNode* ptr = this->root;
        ifor(i, 0, s.length())
        {
            if(ptr->next[s[i] - 'a'] == NULL)
                return false;
            ptr = ptr->next[s[i] - 'a'];
        }
        return ptr->endword;
    }

    bool search_sub_string(string s)
    {
        TrieNode* ptr = this->root;
        ifor(i, 0, s.length())
        {
            if(ptr->next[s[i] - 'a'] == NULL)
                return false;
            ptr = ptr->next[s[i] - 'a'];
        }
        return true;
    }
};

int main()
{
    //Code
    Trie* trie = new Trie();
    trie->insert("ujjawal");
    trie->insert("ujju");
    trie->insert("golu");
    trie->insert("gola");
    trie->insert("richa");
    trie->insert("kaju");

    cout << trie->search_string("ujjawal");
    cout << trie->search_string("kaju");
    cout << trie->search_string("bunty");

    cout <<  trie->search_sub_string("ujj");
    cout <<  trie->search_sub_string("rich");
    cout <<  trie->search_sub_string("kaju");
    cout <<  trie->search_sub_string("bun");

    return 0;
}