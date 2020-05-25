class Solution {
public:
    string entityParser(string text) {
        int len = text.size();
        
        string res = "";
        
        for(int i=0; i<len; i++)
        {
            if(text[i] == '&')
            {
                //&quot;
                if(i + 5 < len)
                {
                    if(text.substr(i, 6) == "&quot;")
                    {
                        res += "\"";
                        i += 5;
                        continue;
                    }
                }
                
                //&apos;
                if(i + 5 < len)
                {
                    if(text.substr(i, 6) == "&apos;")
                    {
                        res += "\'";
                        i += 5;
                        continue;
                    }
                }
                
                //&amp;
                if(i + 4 < len)
                {
                    if(text.substr(i, 5) == "&amp;")
                    {
                        res += "&";
                        i += 4;
                        continue;
                    }
                }
                
                //&gt;
                if(i + 3 < len)
                {
                    if(text.substr(i, 4) == "&gt;")
                    {
                        res += ">";
                        i += 3;
                        continue;
                    }
                }
                
                // &lt;
                if(i + 3 < len)
                {
                    if(text.substr(i, 4) == "&lt;")
                    {
                        res += "<";
                        i += 3;
                        continue;
                    }
                }
                
                // &frasl;
                if(i + 6 < len)
                {
                    if(text.substr(i, 7) == "&frasl;")
                    {
                        res += "/";
                        i += 6;
                        continue;
                    }
                }
                
                
                res += text[i];
                
            }
            
            else
            {
                res += text[i];
            }
        }
        
        return res;
    }
};