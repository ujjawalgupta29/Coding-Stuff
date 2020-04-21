/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int bsearch(BinaryMatrix &mat, int i, int l, int r)
    {
        while(l <= r)
        {
            int mid = (l+r)/2;
            int num = mat.get(i, mid);
            if(num == 1 && (mid == 0 || mat.get(i, mid-1) != 1))
                return mid;
            else if(num == 0)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return -1;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0];
        int n = dim[1];
        
        int idx = -1;
        for(int i=0; i<m; i++)
        {
            int temp = bsearch(binaryMatrix, i, 0, n-1);
            // cout << temp << endl;
            
            if(idx == -1 && temp >= 0 && temp < n)
                idx = temp;
            else if(temp >= 0 && temp < n)
                idx = min(idx, temp);
            
            // cout << "idx= " << idx << endl;
                
        }
        
        return idx;
    }
};