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

void reverse(char* start)
{
    char* end = start;
    while(*end)
    {
        end++;
    }
    end--;

    while(start < end)
    {
        swap(*start, *end);
        start++;
        end--;
    }

}

int main()
{
    //Code
    char str[20];
    cin >> str;
    char* start = str;
    reverse(start);
    printf("%s\n", str);
    return 0;
}