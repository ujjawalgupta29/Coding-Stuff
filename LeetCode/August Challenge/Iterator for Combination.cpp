class CombinationIterator {
public:
    string s;
    vector<int> bits;
    vector<long long int> factorial;
    int comb;
    int counts = 0;
    
    long long int fact(int n)
    {
        if(factorial[n] != 0)
            return factorial[n];
        
        factorial[0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            factorial[i] = factorial[i-1] * i;
        }
        
        return factorial[n];
    }
    
    CombinationIterator(string s, int combLen) {
        factorial.resize(16, 0);
        this->s = s;
        int len = s.size();
        int zeroes = combLen;
        int ones = len - combLen;
        
        // cout << fact(len) << " " << fact(zeroes) << " " << fact(ones) << endl;
        
        comb = fact(len) / (fact(zeroes) * fact(ones));
        
        while(zeroes--)
            bits.push_back(0);
        
        while(ones--)
            bits.push_back(1);
        
        
        
        // cout << "Comb = " << comb << endl;
    }
    
    string next() {
        string res;
        for(int i=0; i<bits.size(); i++)
        {
            if(bits[i] == 0)
                res += s[i];
        }
        
        
        // cout << "start:- ";
        // for(int x : bits)
        //     cout << x << " ";
        // cout << endl << endl;
        
        counts++;
        next_permutation(bits.begin(), bits.end());
        
        return res;
    }
    
    bool hasNext() {
        if(counts < comb)
            return 1;
        else
            return 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */