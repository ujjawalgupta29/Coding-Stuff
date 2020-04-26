class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int max_sum = 0;
        int n = cards.size();
        
        int sum = 0;
        for(int i=0; i<k; i++)
            sum += cards[i];
        if(sum > max_sum)
            max_sum = sum;
        
        for(int i=0; i<k; i++)
        {
            sum = sum - cards[k - 1 - i];
            sum += cards[n-1-i];
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
    }
};