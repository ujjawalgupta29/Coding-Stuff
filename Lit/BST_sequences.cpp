#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<long long> VL;
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

VV bstSeq(Node* root)
{
    if(root == NULL)
    {
        VI temp;
        VV res_temp;
        res_temp.push_back(temp);
        return res_temp;
    }

    VV left = bstSeq(root->left);
    VV right = bstSeq(root->right);

    VV res;

    VI flags(left[0].size(), 0);
    ifor(i, 0, right[0].size())
        flags.push_back(1);

    int total_sz = left[0].size() + right[0].size() + 1;

    ifor(i, 0, left.size())
    {
        ifor(j, 0, right.size())
        {
            do
            {
                VI temp(total_sz);
                temp[0] = root->val;
                int l = 0, r = 0;
                for(int k = 0; k < flags.size(); k++)
                    temp[k+1] = (flags[k]) ?  right[j][r++] : left[i][l++] ;
                res.push_back(temp);
            } while (next_permutation(flags.begin(), flags.end()));
            
        }
    }

    return res;
}

int main()
{
    //Code
    // Node* root = new Node(5);
    // root->right = new Node(7);
    // root->right->left = new Node(6);
    // root->right->right = new Node(10);
    // root->left = new Node(4);
    // root->left->left = new Node(1);

    Node* root = new Node(5);
    root->right = new Node(7);
    root->left = new Node(4);

    VV res = bstSeq(root);

    for(int i = 0; i<res.size(); i++)
    {
        for(int x : res[i])
            cout << x << " ";
        cout << endl;
    }

    cout << endl;

    return 0;
}