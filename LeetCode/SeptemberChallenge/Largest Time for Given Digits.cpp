class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string res;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(i!=j)
                    for(int k=0; k<4; k++)
                    {
                        if(j != k && k!=i)
                        for(int l=0; l<4; l++)
                        {
                            if(k!=l && l!=j && l!=i)
                            {
                                string temp = to_string(A[i]) + to_string(A[j]) + ":" + 
                                    to_string(A[k]) + to_string(A[l]);
                                // cout << temp << endl;
                                
                                
                                if(stoi(temp.substr(0,2)) < 24 && stoi(temp.substr(3,2)) < 60)
                                {
                                    if((res.size() == 0) || (stoi(temp.substr(0,2)) > stoi(res.substr(0,2)))
                                      || (stoi(temp.substr(0,2)) == stoi(res.substr(0,2)) && 
                                        stoi(temp.substr(3,2)) > stoi(res.substr(3,2))))
                                          res = temp;
                                }
                            }
                        }
                    }
            }
        }
        
        return res;
    }
};