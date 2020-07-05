class Solution:
    def arrangeCoins(self, num: int) -> int:
        num = num*2;
        first = ( -1 + sqrt(1 + 4*1*(num)) )/ (2);
        
        return int(first)
        