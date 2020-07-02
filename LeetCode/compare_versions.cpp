class Solution {
public:
    
    void printDots(vector<int> dots) {
        for(int x : dots)
            cout << x << " ";
        cout << endl;
    }
    
    int compareVersion(string v1, string v2) {
        vector<int> dots1;
        vector<int> dots2;
        dots1.push_back(-1);
        dots2.push_back(-1);
        
        int n1 = v1.size();
        int n2 = v2.size();
        
        for(int i=0; i<n1; i++) {
            if(v1[i] == '.')
                dots1.push_back(i);
        }
        
        for(int i=0; i<n2; i++) {
            if(v2[i] == '.')
                dots2.push_back(i);
        }
        
        dots1.push_back(n1);
        dots2.push_back(n2);
        
        int len1 = dots1.size();
        int len2 = dots2.size();
        
        // printDots(dots1);
        // printDots(dots2);
        
        int comparisons = min(len1, len2) - 1;
        
        for(int i=1; i<=comparisons; i++) {
            string s1 = v1.substr(dots1[i-1]+1, dots1[i]-dots1[i-1]-1);
            string s2 = v2.substr(dots2[i-1]+1, dots2[i]-dots2[i-1]-1);
            int num1 = stoi(s1);
            int num2 = stoi(s2);
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
        }
        
        if(len1 == len2)
            return 0;
        
        else if(len1 > len2) {
            for(int i=dots1[comparisons]+1; i<n1; i++)
            {
                if(v1[i] == '.' || v1[i] == '0')
                    continue;
                else
                    return 1;
            }
        }
        
        else {
            for(int i=dots2[comparisons]+1; i<n2; i++)
            {
                if(v2[i] == '.' || v2[i] == '0')
                    continue;
                else
                    return -1;
            }
        }
        
        return 0;
    }
};