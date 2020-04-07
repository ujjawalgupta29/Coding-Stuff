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
            if(s[i] == ' ')
            {
                if(ptr->next[26] == NULL)
                    ptr->next[26] = new TrieNode();
                else
                {
                    ptr = ptr->next[26];
                }
                
            }

            else if(ptr->next[s[i] - 'a'] == NULL)
            {
                ptr->next[s[i] - 'a'] = new TrieNode();
                ptr = ptr->next[s[i] - 'a'];
            }

        }
        ptr->endword = true;
    }

    bool search_sub_string(string s)
    {
        TrieNode* ptr = this->root;
        ifor(i, 0, s.length())
        {
            if(s[i] == ' ')
            {
                if(ptr->next[26] == NULL)
                    return false;
                ptr = ptr->next[26];
            }
            else
            {
                if(ptr->next[s[i] - 'a'] == NULL)
                    return false;
                ptr = ptr->next[s[i] - 'a'];
            }
            
        }
        return true;
    }
};

int main()
{
    //Code
    string big_string;
    getline(cin, big_string);
    // cin >> big_string;
    int n;
    cin >> n;

    VS small_string(n);
    ifor(i, 0, n)   cin >> small_string[i];

    Trie* trie = new Trie();
    
    ifor(i, 0, big_string.size())
    {
        trie->insert(big_string.substr(i));
    }

    for(auto x : small_string)
    {
        cout << trie->search_sub_string(x) << " ";
    }

    cout << endl;

    return 0;
}