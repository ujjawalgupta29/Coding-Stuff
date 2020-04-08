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

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    stack<Node*> s;
    Node* curr = root;

    while(curr != NULL || !s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->val << " ";

        curr = curr->right;
    }
}

int main()
{
    //Code
    Node* root = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(9);

    inorder(root);
    cout << endl;

    return 0;
}