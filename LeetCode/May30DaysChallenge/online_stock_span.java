class StockSpanner {
    Stack<Integer> prices;
    Stack<Integer> counts;
    public StockSpanner() {
        prices = new Stack<>();
        counts = new Stack<>();
    }
    
    public int next(int price) {
        int res = 1;
        while(!prices.empty() && prices.peek() <= price)
        {
            res += counts.peek();
            counts.pop();
            prices.pop();
        }
        prices.push(price);
        counts.push(res);
        
        return res;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */