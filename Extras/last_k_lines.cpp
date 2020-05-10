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

int main()
{
    //Code
    int k;
    cin >> k;
    string filename;
    cin >> filename;

    ifstream file(filename);
    VS res(k);
    int ptr = 0;
    while(file.peek() != EOF)
    {
        getline(file, res[ptr%k]);
        ptr++;
    }

    int start = (ptr > k) ? ptr%k : 0;
    int counts = min(ptr, k);
    cout << ptr << " " << k << " " << counts << endl;

    for(int i=0; i<counts; i++)
    {
        cout << res[(i+start)%k] << endl;
    }
    
    return 0;
}