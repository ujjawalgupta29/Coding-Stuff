class Solution {
public:
    
    vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty",
                          "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> below20 = {"One", "Two", "Three","Four","Five","Six",
                             "Seven","Eight","Nine","Ten","Eleven","Twelve",
                             "Thirteen","Fourteen","Fifteen","Sixteen",
                             "Seventeen","Eighteen","Nineteen"};
    
    string convert(int n)
    {
        if(n >= 1000000000)
            return convert(n/1000000000) + " Billion" + 
            convert(n - 1000000000 * (n / 1000000000));
        
        else if(n >= 1000000)
            return convert(n/1000000) + " Million" + convert(n -1000000 * (n / 1000000));
        
        else if(n >= 1000)
            return convert(n/1000) + " Thousand" + convert(n - 1000 * (n / 1000));
        
        else if(n >= 100)
            return convert(n/100) + " Hundred" + convert(n - 100 * (n / 100));
        
        else if(n >= 20)
            return " " + tens[n/10 - 2] + convert(n - 10 * (n / 10));
        
        else if(n >= 1)
            return " " + below20[n - 1];
        
        else 
            return "";
    }
    
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        return convert(num).substr(1);
    }
};