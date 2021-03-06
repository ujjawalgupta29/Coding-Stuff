    class Solution {
    public:
        vector<int> countBits(int num) {
    //         vector<int> res;
    //         for(int i=0; i<= num; i++)
    //         {
    //             res.push_back(bitset<32>(i).count());
    //         }

    //         return res;
            vector<int> res(num+1, 0);

            for(int i=1; i<=num; i++)
            {
                res[i] = res[i & (i-1)] + 1;
            }

            return res;
        }
    };