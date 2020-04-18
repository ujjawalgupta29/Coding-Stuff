class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> heap;
        for(int i=0; i<n; i++)
        {
            heap.push(stones[i]);
        }
        
        while(heap.size() > 1)
        {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            cout << x << " " << y << endl;
            if(x == y)
                continue;
            else
            {
                heap.push(abs(x-y));
            }
        }
        
        return (heap.size() == 0) ? 0 : heap.top();
    }
};