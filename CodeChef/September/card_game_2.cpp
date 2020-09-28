#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define v(N) vector<int> v(N)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int mod = 1e9+7;

ull power(ull number, int expo, int mod) 
{ 
    ull res = 1; 
    number = number % mod; 
  
    while (expo > 0) 
    { 
        if (expo & 1) 
            res = (res * number) % mod; 
  
        expo = expo / 2;
        number = (number * number) % mod; 
    } 
    return res; 
} 
  
ull inverse(ull N, int mod) 
{ 
    return power(N, mod - 2, mod); 
} 
  
ull combinations(ull N, 
                                 int R, int mod, ull factorials[]) 
{ 
    if (R == 0) 
        return 1;  
  
    return (factorials[N] * inverse(factorials[R], mod) % mod * inverse(factorials[N - R], mod) % mod) % mod; 
}

void solve(int N, unordered_map<int, int> &frequency_of_card, int max_value)
{
    int nums = N - frequency_of_card[max_value];
    long long result_combinations = power(2, nums, mod);

    int min_req = frequency_of_card[max_value] / 2 + 1;
    long long combinations_cards = 0;

    ull factorials[N + 1]; 
    factorials[0] = 1; 
    for (int i = 1; i <= N; i++) 
        factorials[i] = (factorials[i - 1] * i) % mod; 

    for(int i=min_req; i<=frequency_of_card[max_value]; i++)
    {
        long long temp_combinations = combinations(frequency_of_card[max_value], i, mod, factorials);
        combinations_cards = (combinations_cards + temp_combinations) % mod; 
    }

    result_combinations = (result_combinations * combinations_cards) % mod;
    result_combinations = (result_combinations * 2) % mod;
    cout << result_combinations << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        vector<int> card_numbers(N);
        int max_value = INT_MIN;
        unordered_map<int, int> frequency_of_card;

        for(int i=0; i<N; i++)
        {
            cin >> card_numbers[i];
            frequency_of_card[card_numbers[i]]++;
            max_value = max(max_value, card_numbers[i]);
        }

        solve(N, frequency_of_card, max_value);
    }
    
}